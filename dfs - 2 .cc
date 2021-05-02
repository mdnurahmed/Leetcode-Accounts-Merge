#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    //edge[i] holds all the nodes that are adjacent to node i
    unordered_map<string,unordered_set<string>>edge;
    //visited holds the nodes that are already visited in the dfs 
    unordered_set<string>visited;
    // s contains all the emails in one dfs traversal meaning  in the current component of the graph
    set<string> s;

    //this method runs the dfs to find all the emails that belongs to one person 
    void dfs(string email) {
        visited.insert(email);
        // all the emails in this component belongs to same person 
        s.insert(email);
        for (auto neighbour:edge[email]) {
            //if this node is visited already we wont visit it again 
            if (visited.find(email) == visited.end()) {
                dfs(neighbour);
            }
        }
    }

    //this method solves the problem and returns the result 
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc) {
        //initializing visited vector 
        visited.clear();

        //constructing the graph 
        for (int i = 0; i < acc.size(); i++) {
            for (int j = 1; j < acc[i].size(); j++) {
                for(int k = j+1; k < acc[i].size(); k++){
                    edge[acc[i][j]].insert(acc[i][k]);
                    edge[acc[i][k]].insert(acc[i][j]);
                }
            }
        }


        //result vector that we shall return 
        vector<vector<string>> res;
        for (int i = 0; i < acc.size(); i++) {
            for(int j = 1; j < acc[i].size(); j++){
                if (visited.find(acc[i][j]) != visited.end()){
                    vector<string> v;
                    v.push_back(acc[i][0]);
                    //find all the emails that belongs to the person acc[i][0]
                    dfs(acc[i][j]);
                    for (auto it = s.begin(); it != s.end(); it++) {
                        v.push_back(*it);
                    }
                    s.clear();
                    res.push_back(v);
                }
            }
        }

        return res;
    }
};

int main(){

}