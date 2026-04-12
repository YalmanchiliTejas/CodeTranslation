#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

int N,M;
int A[100],B[100];
vector<int> V[10];
bool used[10];
int ans = 0;

void dfs(int X){
    bool end = 1;
    REP(i,N) if(!used[i] && i != X) end = 0;
    if(end){
        ans++;
        return;
    }if(used[X])return;else used[X] = 1;
    REP(i,V[X].size()){
        dfs(V[X][i]);
    }
    used[X] = 0;
}

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);cin >> N >> M;
    REP(i,M){
        cin >> A[i] >> B[i];--A[i];--B[i];
        V[A[i]].pb(B[i]);V[B[i]].pb(A[i]);
    }
	dfs(0);
    cout << ans << endl;
}