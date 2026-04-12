#include <bits/stdc++.h>

#define task "E"
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (ll i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (ll i = (r); i >= (l); --i)
#define DB(X) { cerr << #X << " = " << (X) << '\n'; }
#define db1(A, _) { cerr << #A << "[" << _ << "] = " << (A[_]) << '\n'; }
#define db2(A, _, __) { cerr << #A << "[" << _ << "][" << __ << "] = " << (A[_][__]) << '\n'; }
#define db3(A, _, __, ___) { cerr << #A << "[" << _ << "][" << __ << "][" << ___ << "] = " << (A[_][__][___]) << '\n'; }
#define PR(A, n) { cerr << #A << " = "; rep(_, 1, n) cerr << A[_] << ' '; cerr << '\n'; }
#define SZ(x) ((ll)(x).size())
#define pb push_back
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
string s;
ll k;
ll res;
inline ll C(ll k, ll n)
{
    if (k > n) return 0;
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k == 2) return n * (n - 1) / 2;
    return n * (n - 1) * (n - 2) / 6;
}
inline ll mu(ll k)
{
    if (k == 0) return 1;
    if (k == 1) return 9;
    if (k == 2) return 9 * 9;
    return 9 * 9 * 9;
}
void Solve(ll pos, ll num_l)
{
    if (pos == SZ(s) && num_l > 0)
    {
        res --;
        return;
    }
    if (pos == SZ(s) || num_l == 0) return;
    rep(i, 0, s[pos] - '1') res += C(num_l - (i != 0), SZ(s) - pos - 1) * mu(num_l - (i != 0));
    Solve(pos + 1, num_l - (s[pos] != '0'));
}
int main()
{
	//freopen(task".in","r",stdin);
	//freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> s >> k;
	if (SZ(s) < k)
    {
        cout << 0;
        return 0;
    }
	Solve(0, k);
	cout << res + 1;
}
