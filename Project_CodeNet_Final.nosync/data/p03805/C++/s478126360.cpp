#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin,(obj).end()
#define SORT(list) sort(ALL((list)));
using namespace std;
using ll = long long;
vector<int> ad[8];
vector<bool> visited(8,0);
int answer;
void dfs(int i,int n){
    visited[i]=true;
    bool all_visited = true;
    REP(i,n){
        if(!visited[i]){
            all_visited = false;
        }
    }
    if(all_visited){
        answer++;
    }
    for(int v:ad[i]){
        if(visited[v])continue;
        dfs(v,n);
    }
    visited[i]=false;
}
int main(){
    int n,m;
    cin >> n >> m;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        ad[a-1].push_back(b-1);
        ad[b-1].push_back(a-1);
    }
    dfs(0,n);
    cout << answer << endl;
    return 0;
}