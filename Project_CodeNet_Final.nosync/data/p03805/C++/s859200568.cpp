#include "bits/stdc++.h"
using namespace std;
#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
typedef long long ll;

const int INF = 1e9;
const long long LLINF = 1e18;

int n, m;
bool edge[8][8];
int dfs(int cur, bool visited[]){
    bool flag=true;
    REP(i, 0, n){
        if(visited[i]==false){
            flag=false;
            break;
        }
    }
    if(flag) return 1;

    int cnt=0;
    REP(i, 0, n){
        if(edge[cur][i]==false) continue;
        if(visited[i]==true) continue;

        visited[i]=true;
        cnt+=dfs(i, visited);
        visited[i]=false;
    }
    return cnt;
}
int main() {
    cin>>n>>m;
    REP(i, 0, m){
        int a, b;
        cin>>a>>b;
        edge[a-1][b-1]=true;
        edge[b-1][a-1]=true;
    }

    bool visited[8];
    REP(i, 0, 8) visited[i]=false;

    visited[0]=true;
    cout<<dfs(0, visited)<<endl;
    return 0;
}