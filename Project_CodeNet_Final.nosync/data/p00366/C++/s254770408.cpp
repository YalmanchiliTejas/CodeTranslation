#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<int ,P> P3;
typedef pair<P ,P> PP;
const ll MOD = ll(1e9+7);
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-6;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

vector<ll> divisor(ll x){
    vector<ll> res;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            res.push_back(i);
            if(x/i!=i) res.push_back(x/i);
        }
    }
    SORT(res);
    return res;
}

int main() {
    ll n, t[MAX_N], ma = 0, ans = 0;
    cin >> n;
    REP(i,n){
        cin >> t[i];
        ma = max(ma, t[i]);
    }
    vector<ll> ls = divisor(ma);
    REP(i,n){
        ans += *lower_bound(ALL(ls),t[i]) - t[i];
    }
    cout << ans << endl;
    return 0;
}

