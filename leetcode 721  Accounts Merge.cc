#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    //edge[i] holds all the nodes that are adjacent to node i
    unordered_set<int>edge[1002];
    //visited holds the nodes that are already visited in the dfs 
    vector<bool> visited;
    // s contains all the emails in one dfs traversal meaning  in the current component of the graph
    set<string> s;

    //this method runs the dfs to find all the emails that belongs to one person 
    void dfs(int i, vector<vector<string>> &acc) {
        visited[i] = true;
        // all the emails in this component belongs to same person 
        for (int j = 1; j < acc[i].size(); j++) {
            s.insert(acc[i][j]);
        }
        for (auto neighbour:edge[i]) {
            //if nofe i is visited already we wont visit it again 
            if (!visited[neighbour]) {
                dfs(neighbour, acc);
            }
        }
    }

    //this method solves the problem and returns the result 
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc) {
        //initializing visited vector 
        visited.resize(acc.size() + 2, false);

        //this hash map hold all the indexes where an email was seen before 
        unordered_map<string, vector<int>> mp; 

        //constructing the graph 
        for (int i = 0; i < acc.size(); i++) {
            for (int j = 1; j < acc[i].size(); j++) {

                //All the idnexes are neighbour of node i where email acc[i][j] was seen before
                if (mp.find(acc[i][j]) != mp.end()) {
                    for (auto neighbour : mp[acc[i][j]]) {
                        edge[i].insert(neighbour);
                        edge[neighbour].insert(i);
                    }
                }
                mp[acc[i][j]].push_back(i);
            }
        }


        //result vector that we shall return 
        vector<vector<string>> res;
        for (int i = 0; i < acc.size(); i++) {
            if (!visited[i]) {
                vector<string> v;
                v.push_back(acc[i][0]);
                //find all the emails that belongs to the person acc[i][0]
                dfs(i, acc);
                for (auto it = s.begin(); it != s.end(); it++) {
                    v.push_back(*it);
                }
                s.clear();
                res.push_back(v);
            }
        }

        return res;
    }
};

int main(){

}