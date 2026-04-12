#include<iostream>
#include<deque>
using namespace std;
deque<deque<int>> s(100);
deque<bool> seen;
int d;
int t = 0;
int n;
void dfs(int a){
    d++;
    seen[a] = true;
    if(d == n)t++;
    for(auto i : s[a]){
        if(seen[i])continue;
        else dfs(i);
        }
    seen[a] = false;
    d--;
}    
        
int main(){

int m;cin >> n >> m;

for(int i = 0; i < m; i++){
    int x,y;cin >> x >> y;
    s[y].push_back(x);
    s[x].push_back(y);
    }
d = 0;
seen.assign(n, false);
dfs(1);

cout << t << "\n";
}