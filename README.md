# Leetcode-Accounts-Merge
My solution for the problem [Leetcode 721 Accounts Merge](https://leetcode.com/problems/accounts-merge/)

## Problem Description 
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

## Examples

### Example - 1 

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

### Example - 2

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]


### Constraints:

- 1 <= accounts.length <= 1000
- 2 <= accounts[i].length <= 10
- 1 <= accounts[i][j] <= 30
- accounts[i][0] consists of English letters.
- accounts[i][j] (for j > 0) is a valid email.


## Solution Approach 
If any email appears in mutliple accounts then we can assume all the emails in all those accounts belong to same person .

In other words , if any email in accounts[i] also appear in account[j] then all the emails in those 2 accounts belong to same graph component . All the emails belonging to a single graph component belong to one person . We can find all the emails in one component using depth first search or disjoint set union algorithm . Here I used depth first search.

## Complexity Analysis 
# Time Complexity of Constructing the graph 
We can construct the graph in two ways. We can assume the accounts as nodes or emails as nodes of the graph. 

We can draw an edge between two accounts if they have any common emails. Complexity of this approach is O(A^2*E) where A is number of accounts and E is number of Email in one account.

Another way is we can draw an edge from an email to all the emails in the same account.Complexity of this approach is O(A*E^2) where A is number of accounts and E is number of Email in one account.

# Time Complexity of Depth First Search
No node (email or account) is visited twice. The problem wants us to sort the results. If we use C++ Set to store all the emails of one component , then it helps us to avoid overcounting same email and with sorting the emails in logarithmic time as it uses a balanced binary search tree underneath and sorts elements in real time . So overall complexity is AElog(AE) where A is number of accounts and E is number of Email in one account.

# Overall Time Complexity 
Overall time complexity is O(A^2*E) + O(AElog(AE)) in the first solution and A*E^2 + AElog(AE) in the second solution where A is number of accounts and E is number of Email in one account.

# Space Complexity of Constructing the graph 
In the first solution it takes O(A) space for the visited vector, O(A^2) space to store the graph , O(É) space to store the results temporatily in the set where A is number of accounts and E is number of Email in one account , É is total number of emails.

In the second solution it takes O(É) space for the visted hashset . O(É^2) space to store the graph , O(É) space to store the results temporatily in the set where É is total number of emails.

# Space Complexity of Depth First Search 
In the first solution the dfs takes O(A) stack space. In the second solution the dfs takes O(É) stack space where A is number of accounts and É is total number of emails.

# Overall Space Complexity
Overall space complexity of first solution is O(A) + O(A^2) + O(É) + O(A) ~ O(A^2) + O(É) . Overall space complexity of second solution is O(É) + O(É^2) + O(É) + O(É) ~ O(É^2)


## Alternative Approach 
We can use disjoint set union to solve this problem online instead of offline where we gotta construct the graph first and then do dfs . 