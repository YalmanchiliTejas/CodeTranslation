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

ll func(ll n, ll k)
{
    ll L = 1, M = (1LL<<(n+1))-1, R = (1LL<<(n+2))-3;
    ll P = (1LL<<n)-1;
    if(n > 0) {
        if(k == L) return 0;
        else if(L < k && k < M) return func(n-1, k-1);
        else if(k == M) return P + 1;
        else if(M < k && k < R) return func(n-1, k-M) + P + 1;
        else if(k == R) return P * 2 + 1;
        else return 0;
    }
    else return 1;
}

int main()
{
    ll N, X;
    cin >> N >> X;

    ll ans = func(N, X);
    PR(ans);

    return 0;
}

/*



*/