#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a)  (a).rbegin(),(a).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> void PrintVector(const vector<T> &vec) {for (auto val : vec) cout << val << " "; cout << endl;}
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll len(ll n)
{
    return (1LL << n + 2) - 3;
}

ll rec(ll n, ll x)
{
    ll bur = len(n);
    ll patt = (1LL << n + 1) - 1;
    if (x == bur) return patt;

    ll ans = 0;
    x--;
    if (x > 0)
    {
        ll l = min(x, len(n - 1));
        ans += rec(n - 1, l);
        x -= l;
    }
    if (x > 0)
    {
        ans++;
        x--;
    }
    if (x > 0)
    {
        ll l = min(x, len(n - 1));
        ans += rec(n - 1, l);
        x -= l;
    }
    return ans;
}

int main()
{
    ll n, x; cin >> n >> x;
    //COUT(len(1));
    cout << rec(n, x) << endl;
}