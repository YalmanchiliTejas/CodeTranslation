#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, pair<ll, ll> > P3;

const ll MOD = ll(1e9 + 7);
const ll LLINF = LLONG_MAX;
const int IINF = INT_MAX;
const int MAX_N = int(1e5) + 5;
const double EPS = 1e-8;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
string dir[] = {"R", "D", "L", "U"};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll n, q, sum = 0;
    cin >> n >> q;
    REP(i,q){
        ll x, k;
        cin >> x >> k;
        if(x){
            sum += k;
            sum %= n;
        }
        else{
            cout << (sum+k-1)%n+1 << endl;
        }
    }
    return 0;
}

