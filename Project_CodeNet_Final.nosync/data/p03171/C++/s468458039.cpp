//Littleboy123 Template 1.6
#include <bits/stdc++.h>
using namespace std;

//pragmas
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const long double pi = acos(-1.0);

#define FOR(a,b,c) for(ll (a)=(b);(a)<(c);++(a))
#define FORE(a,b,c) for(ll (a)=(b);(a)<=(c);++(a))
#define FORN(a,b,c) for(ll (a)=(b);(a)>(c);--(a))
#define FORNE(a,b,c) for(ll (a)=(b);(a)>=(c);--(a))
#define COUT(n) printf("%d\n", (n))
#define COUTLL(n) printf("%lld\n", (n))
#define CIN(n) scanf("%d", &(n))
#define CINLL(n) scanf("%lld", &(n))
#define MEM(a,b) memset((a), (b), sizeof((a)))
#define MAX(a,b) (a) = max((a), (b))
#define MIN(a,b) (a) = min((a), (b))
#define nl '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void infile(){
	freopen("input.in", "r", stdin);
}

void outfile(){
	freopen("output.out", "w", stdout);
}

ll modex(ll a, ll b, ll mod){
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	ll tmp = modex(a, b/2, mod);
	tmp = (tmp * tmp) % mod;
	if(b & 1)
		tmp = (tmp * a) % mod;
	return tmp;
}

//End of template

int n;
ll arr[3005];
pair<ll, ll> memo[3005][3005];

pair<ll, ll> dp(int l, int r){
	if(l > r)
		return {0, 0};
	pair<ll, ll> salah = {-1, -1};
	if(memo[l][r] != salah){
		return memo[l][r];
	}
	int gantian = 0;
	if(((n-r-1)+l) & 1){
		gantian = 1;
	}
	pair<ll, ll> one, two, ans1, ans2;
	if(gantian & 1){
		one = mp(0, arr[r]);
		two = mp(0, arr[l]);
		ans1 = dp(l, r-1);
		ans2 = dp(l+1, r);
		one.fi += ans1.fi;
		one.se += ans1.se;
		two.fi += ans2.fi;
		two.se += ans2.se;
		if(one.fi - one.se > two.fi - two.se){
			memo[l][r] = two;
		}
		else{
			memo[l][r] = one;
		}
	}
	else{
		one = mp(arr[r], 0);
		two = mp(arr[l], 0);
		ans1 = dp(l, r-1);
		ans2 = dp(l+1, r);
		one.fi += ans1.fi;
		one.se += ans1.se;
		two.fi += ans2.fi;
		two.se += ans2.se;
		if(one.fi - one.se > two.fi - two.se){
			memo[l][r] = one;
		}
		else{
			memo[l][r] = two;
		}
	}
	return memo[l][r];
}

int main(){
	init();
	
	cin >> n;
	FOR(i, 0, n){
		cin >> arr[i];
	}
	FOR(i, 0, 3005){
		FOR(j, 0, 3005){
			memo[i][j] = {-1, -1};
		}
	}
	pair<ll, ll> ans = dp(0, n-1);
	cout << ans.fi - ans.se << nl;
	return 0;	
}