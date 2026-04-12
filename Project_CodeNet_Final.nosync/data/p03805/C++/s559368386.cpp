#include <bits/stdc++.h>
 
using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define VPII vector<PII>
#define LD long double
#define INF 1000000000000
#define MOD 1000000007
#define MAXR 100000 // array max range

int N,M;
vector<vector<bool>> ab;
vector<bool> visited;
vector<int> route;
int dfs(int depth,int now){
    if(depth == N-1){
        R(i,N){
            if(!visited[i]) break;
            if(i==N-1){
                return 1;
            }
        }
        return 0;
    }
    int ans = 0;

    R(i,N){
        if((ab[now][i] || ab[i][now]) && !visited[i]){
            visited[i] = true;
            ans += dfs(depth+1,i);
            visited[i] = false;
        }
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(6);
    cin >> N >> M;
    //ab.assign(M,vector<bool>(M,false));
    ab.assign(N,vector<bool>(N,false));
    visited.assign(N,false);
    int a,b;
    R(i,M){
        cin >> a >> b;
        a--;
        b--;
        ab[a][b] = true;
    }
    visited[0]=true;
    cout << dfs(0,0) << endl;
    return 0;
}
