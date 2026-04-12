#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
const LL MOD=1000000007ll;
const LL INF=2000000000ll;

long power(long a,long b){return b?power(a*a%MOD,b/2)*(b%2?a:1)%MOD:1;}
long comb(int N,int K)
{
    long x=1,y=1;
    for(int i=1;i<=K;i++)
    {
        x=x*(N-i+1)%MOD;
        y=y*i%MOD;
    }
    return x*power(y,MOD-2)%MOD;
}

long hcomb(int N, int K){
    return comb(N+K-1, N-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N, M, t1,t2;
    cin >> N >> M;
    VVI e(N, VI(N,0));
    REP(i,M){
        cin >> t1 >> t2;
        e[t1-1][t2-1] = 1;
        e[t2-1][t1-1] = 1;
    }

    VI order(N-1);
    REP(i,N-1) order[i] = i+1;

    int ans = 0;

    do {
        int cnt = 1;
        if (!e[0][order[0]]) cnt = 0;
        REP(i,N-2){
            if (!e[order[i]][order[i+1]]) cnt = 0;
        }
        if (cnt) ans++;
    } while(next_permutation(ALL(order)));

    cout << ans << endl;
}
