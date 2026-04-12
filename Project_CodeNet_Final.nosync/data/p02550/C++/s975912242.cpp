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
    ll N, X, M;
    cin >> N >> X >> M;

    vec R;
    vec F(M+1, 0);
    ll p = 0, cnt = 1;
    R.pb(X%M);
    F[X%M] = 1;
    while(true) {
        ll r = R.back() % M;
        r = (r * r) % M;
        if(F[r] == 0) {
            ++cnt;
            F[r] = cnt;
            R.pb(r);
        }
        else {
            p = F[r];
            break;
        }
    }

    ll sum = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    ll L = SZ(R) - p + 1;
    REP(i,0,p-1) sum1 += R[i];
    REP(i,p-1,SZ(R)) sum2 += R[i];
    REP(i,p-1,p-1+((N-p+1)%L)) sum3 += R[i];
    sum = sum1 + sum2 * ((N-p+1)/L) + sum3;
    PR(sum);
    
    return 0;
}

/*



*/