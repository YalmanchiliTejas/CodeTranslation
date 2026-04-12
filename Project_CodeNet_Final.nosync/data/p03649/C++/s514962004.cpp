//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ret(a) {cout << a; exit(0);}

using namespace std;

mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

typedef pair < int , int > pii ;
typedef pair < long long  , long long > pll ;

const int N = 2e5 + 1 , K = 501;
int n , m , k;
int a[60];
bool bad(){
	return *max_element(a + 1 , a + 1 + n) > n - 1;
}
bool check(int x){ 
	//a[i] + 2 + x <= (N + 1) * (x[i] - 1)
	//a[i] - k * n + (x - k) <= n - 1
	int tot = 0;
	for(int i = 1 ; i <= n; i++){
	  	int l = 0 , r = min<ll>(x , 1e16 + 1000) , add = 1e16;
	  	while(l <= r){
	  		int m = (l + r) >> 1;
	  		if(a[i] - m * n + (x - m) <= n - 1)
	  			add = m , r = m - 1;
	  		else l = m + 1;
	  	}
	  	tot += add;
	  	if(tot > x)return false;
	}
	return 1;
}
main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> n ;
	int sum = 0;
	for(int i = 1; i <= n ; i++){
//		a[i] = rnd(100 * n) + 1;
//		a[i] = k;
		sum += a[i];
		cin >> a[i];
	}
	int cnt = 0;
	//a[i] + 2 + k  <=  (N + 1) * (x[i] - 1)  ;
	int l = 0 , r = 1e18 , res = 1e18 ;
	//1e13
//	ret(check(475457939086683502ll));
	while(l <= r){
		int m = (l + r) >> 1;
		int pos = -1;
		for(int i = max(m - 50* 50, 0ll) ; i <= m  ; i++)
			if(check(i))
				pos = i, i = m + 1;
							
		if(pos != -1){
			r = pos - 1 ;
			res = pos;
		}
		else l = m + 1;
	}

 	int ans = res;	
 	cerr << res << '\n';

/*	for(int i = res - 1 ; i >= 0 ; i--){
		if(check(i))
			ans = i;
		if(clock()/CLOCKS_PER_SEC > 1.9)break;
	}*/
//	cerr << ' ';
    ret(ans);
}