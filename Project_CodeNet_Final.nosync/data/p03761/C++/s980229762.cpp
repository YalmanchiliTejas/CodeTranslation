#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll n;
    cin >> n;
    vector<string> S(n);
    REP(i,0,n) cin >> S[i];

    mat A(n, vec(26, 0));
    REP(i,0,n) {
        REP(j,0,SZ(S[i])) ++A[i][S[i][j]-'a'];
    }
    vec B(26);
    REP(i,0,26) {
        B[i] = A[0][i];
        REP(j,1,n) B[i] = MIN(B[i],A[j][i]);
    }
    REP(i,0,26) {
        REP(j,0,B[i]) cout << (char)(i+'a');
    }
    cout << endl;

    return 0;
}

/*



*/