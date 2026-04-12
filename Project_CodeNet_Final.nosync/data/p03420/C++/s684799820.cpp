#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,n) for(int i=1;i<=(int)(n);i++)
#define rep3(i,n) for(int i=0;i<=(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
#define repll(i,n) for(ll i=0;i<(ll)(n);i++)
#define repll2(i,n) for(ll i=1;i<=(ll)(n);i++)
#define REPLL(i,m,n) for(ll i=m;i<(ll)(n);i++)
#define INF 1000000000 //
#define LINF (ll)4000000000000000000 //
#define MOD (ll)1000000007
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define PI 3.1415926535898
#define NP(v) next_permutation(v.begin(),v.end())

//------------------------------------------------------

int main() {
    ll n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }

    ll cnt = 0;

    for (ll b = k + 1; b <= n; b++) {
        ll cycle = n / b;
        ll reminder = n % b;
        ll r = reminder - k + 1;
        cnt = cnt + max((ll) 0, ((b - k) * cycle + (ll) max((ll) 0, r)));
    }

    cout << cnt << endl;
    return 0;
}

