#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rrep(i, n) for(int i = (int)(n) - 1; i >= 0; i --)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define mod2 998244353
#define inf 1000000000000000000
#define pi acos(-1)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define print(x) for(auto i : (x)) cout << i << " "; cout << endl
typedef long long ll;
typedef pair<ll, ll> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll dx[] = {-1,0,1,0,-1,-1,1,1};
const ll dy[] = {0,-1,0,1,-1,1,-1,1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans_1 = a * x + b * y;
    ll ans_2 = inf;
    if (a + b > 2*c) {
        ll p = min(x, y), res = 0;
        x -= p;
        y -= p;
        res += 2 * c * p;
        res += min(a, 2 * c) * x + min(b, 2 * c) * y;
        chmin(ans_2, res);
    }
    cout << min(ans_1, ans_2) << endl;
}