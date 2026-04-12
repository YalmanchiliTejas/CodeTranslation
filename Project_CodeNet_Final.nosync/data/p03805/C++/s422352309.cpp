#include<iostream>
#include<deque>
using namespace std;
deque<bool> seen;
deque<deque<int>> v(100);
int k = 0;
int n,m;
void dfs(int number,int depth){
        seen[number] = true;
        if(depth == n) k++;
        for(auto j : v[number])if(!seen[j])dfs( j, depth + 1);
        seen[number] = false;      
}                
int main(void){
cin >> n >> m;

for(int i = 0; i < m; i++){
        int a,b;cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        }
seen.assign(n + 1, false);
dfs(1, 1);

cout << k << "\n";
}