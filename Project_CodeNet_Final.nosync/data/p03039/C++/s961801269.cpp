//by Himanshu Shukla
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define v32 vector<int>
#define v64 vector<ll>
#define s32 set<int>
#define s64 set<ll>
#define graph vector<s32>
#define p32 pair<int,int>
#define p64 pair<ll,ll>
#define fi first
#define se second
#define ln '\n'
#define debug(x) cout << (#x) << ": " << (x) << ln
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }
const double EPS = 1e-6;
const ll MOD = 1e9 + 7;
template <typename T, typename U>
ostream& operator<<(ostream& out, const pair<T,U>& p){
	out << '[' << p.fi << ", " << p.se << ']';
	return out;
}
template <template <typename, typename...> class ContainerType, typename ValueType, typename ...Args>
void print_container(const ContainerType<ValueType, Args...>& c){
	cout << "{ ";
	for(const auto& v : c)
		cout << v << ' ';
	cout << '}' << ln;
}

const int MAX = 2e5 + 5;
ll inv[MAX],fact[MAX],ifact[MAX];

void pre()
{
	fact[0] = fact[1] = ifact[0] = ifact[1] = inv[1] = 1;
	for(int i = 2;i < MAX;i++)
	{
		inv[i] = mul(MOD - (MOD / i),inv[MOD % i],MOD);
		fact[i] = mul(i,fact[i - 1],MOD);
		ifact[i] = mul(ifact[i - 1],inv[i],MOD);
	}
}

ll nCr(ll a,ll b)
{
	if(a < b) return 0;
	ll ans = 1;
	for(ll i = 0;i < b;i++)
		ans = mul(ans,(a - i),MOD);
	ans = mul(ans,ifact[b],MOD);
	return ans;
}

int main()
{
	FASTIO;
	ll n,m,k;
	cin >> n >> m >> k;
	pre();
	ll temp = nCr(n * m - 2,k - 2);
	ll mm = mul(m,m,MOD),nn = mul(n,n,MOD);
	ll ans1 = mul(mm,add(mul(nn,n,MOD),MOD - n,MOD),MOD);
	ans1 = mul(ans1,inv[6],MOD);
	ll ans2 = mul(nn,add(mul(mm,m,MOD),MOD - m,MOD),MOD);
	ans2 = mul(ans2,inv[6],MOD);
	cout << mul(temp,add(ans1,ans2,MOD),MOD) << ln;
	return 0;
}
