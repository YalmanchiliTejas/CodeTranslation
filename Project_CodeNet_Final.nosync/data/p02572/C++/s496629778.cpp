//#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <string>
#include <stdbool.h>
#include<ctime>

#include <cstring>

#define pub push_back


#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ll long long
//#define max(a,b) ((a) > (b) ? (a) : (b))
//#define min(a,b) ((a) < (b) ? (a) : (b))

#define getI(a) scanf("%d",&a)
#define getII(a, b) scanf("%d%d",&a,&b)
#define getIII(a, b, c) scanf("%d%d%d",&a,&b,&c)
#define getL(a) scanf("%lld",&a)
#define getLL(a, b) scanf("%lld%lld",&a,&b)
#define getLLL(a, b, c) scanf("%lld%lld%lld",&a,&b,&c)
#define BEND(c) (c).begin(),(c).end()
#define BEND2(c) (c).rbegin(),(c).rend()
#define fi first
#define se second
#define pi 3.1415926535897932384626
#define getS(a) scanf("%s",a)
#define pfb(a) printf("%.10lf\n",a);
#define pfi(a) printf("%d",a);
#define pfii(a, b) printf("%d%d",a,b);
#define pfl(a) printf("%lld",a);
#define pfll(a, b) printf("%lld%lld",a,b);
#define pfd(a) printf("%.12lf ",a);
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n"

#define MOD  ( int)(1e9 + 7)
#define MAXN (ll) ((1e5+5))
#define K 25
#define  ALPHABET_SIZE  26
//#define N (int)(1e5+10)
#define sag (sol|1)
#define sol (root<<1)
#define ort (bas+son)/2
#define INF (ll )1e18
#define int ll
using namespace std;






typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int, int>>> vvpi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<long long, long long>> vpl;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<vi> graph;

vector<ll> fact;
vector<ll> fact2;
void finit(int n);
ll exp(ll taban, ll us, ll md);
ll ebob(ll a, ll b);
ll ekok(ll a, ll b);
ll comb(ll a, ll b);


void finit(int n){
	fact.resize(n + 5);
	fact2.resize(n + 5);
	fact[0] = fact2[0] = 1;
	for (int i = 1; i <= n; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
		fact2[i] = exp(fact[i], MOD - 2, MOD);
	}
}
ll exp(ll taban, ll us, ll md) {
	ll carpan = taban % md;
	if (carpan == 0) return 0;
	ll temp = us;
	ll ans = 1;
	while (temp){
		if (temp % 2) ans = (ans*carpan) % md;
		temp /= 2;
		carpan = (carpan*carpan) % md;
	}
	return ans;
}

ll ebob(ll a, ll b){
	if (!a)return b;
	return ebob(b%a, a);
}

ll ekok(ll x, ll y){
	return (x*y) / ebob(x, y);
}

ll comb(ll x, ll y){
	if (x < y) return 0;
	return fact[x] * ((fact2[x - y] * fact2[y]) % MOD) % MOD;
}












ll n, k;
ll res;
ll d, m;
ll t = 1, x, y, p, q;
vi vis(MAXN);
ll mx = 0;
vi vec(MAXN);
string ans; 

void f(vi &a, ll sum ){
	const int size = a.size();
	if (size == 2){
		if (a[0] == a[1])ans = "HL";
		else ans = "T";
	}
	if (vec[0] > sum - vec[0]){
		ans = "T";
		return;
	}
	vi newa;
	ll newsum = 0;
	for (int i = 0; i <size ; i+=2){
		if (a[i] - a[i + 1] != 0 )
			newa.pub(a[i] - a[i + 1]);
		newsum += a[i] - a[i + 1];
	}
	if (size & 1)newa.pub(a[size-1]);
	sort(BEND2(newa));
	f(newa , newsum );


}

signed main(){

	IOS;
	//cin >> t;

	while (t--){
		cin >> n;
		vec.resize(n);
		ll sum = 0;
		for (int a , i = 0; i < n; i++){
			cin >> a;
			vec[i] = a % MOD;
			sum = ( sum + vec[i]) % MOD;
			
		}
		for (int i = 0; i < n - 1; i++){
			sum =(sum -  vec[i] + MOD)%MOD ;
			res = (res+ vec[i] * sum) % MOD;
			
		}
		cout << res << endl;

	}



	getchar(); getchar();

	return 0;

}

/*





*/