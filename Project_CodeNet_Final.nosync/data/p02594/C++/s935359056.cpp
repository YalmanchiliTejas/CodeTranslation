#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define cerr cout
#define F first
#define S second
#define fori(i,a,b) for (i = a; i < b; ++i)
#define ford(i,a,b) for(i = a; i>=b;--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int(x.size())
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vl;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fill(a, x) memset(a, x, sizeof(a))
#define INF 1000000000
#define MOD 1000000007
#define SMOD 998244353
#define endl "\n"
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
const ll N = 100043;
ll fact[N];
ll add(ll x, ll y)
{
	x += y;
	while(x >= MOD) x -= MOD;
	while(x < 0) x += MOD;
	return x;
}
ll mul(ll x, ll y)
{
	return (x * 1ll * y) % MOD;
}
ll mulmod(ll a, ll b)
{
    ll res = 0;
    a = a % MOD;
    while (b>0)
    {
        if (b % 2 == 1)
            res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res % MOD; 
}
ll binpow(ll x, ll y)
{
	ll z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}
ll inv(ll x)
{
	return binpow(x, MOD - 2);
}
ll divide(ll x, ll y)
{
	return mul(x, inv(y));
}
void precalc()
{
	fact[0] = 1;
	ll i;
	fori(i, 1, N)
		fact[i] = mul(i, fact[i - 1]);
}
ll C(ll n, ll k)
{
	if(k > n)
	    return 0;
	return divide(fact[n], mul(fact[n - k], fact[k]));
}

void solve()
{
    int n;
    cin >> n;
    if(n>=30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    // cin >> t;
    for(int i=1; i<=t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}