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
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    ll Zmin = MIN(X,Y), Zmax = MAX(X,Y);
    ll D1 = A*X + B*Y;
    ll D2 = A*MAX(X-Zmin,0) + B*MAX(Y-Zmin,0) + 2*C*Zmin;
    ll D3 = 2*C*Zmax;
    PR(MIN(MIN(D1,D2),D3));
    

    return 0;
}

/*



*/