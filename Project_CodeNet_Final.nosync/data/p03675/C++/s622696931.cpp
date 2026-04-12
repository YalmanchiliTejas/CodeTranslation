//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector") 
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int N = 2e5 + 123;

int n , m , k , a[N] , d;

main(){                                                                   	
	cin >> n ;
	deque < int > dq;
	for(int i = 1 ; i <= n ; i++)
		scanf("%lld" , a + i);
	for(int i = 1 ;i <= n; i++){
		if(i % 2 == 1)
			dq.push_front(a[i]);
		else dq.push_back(a[i]);
	}
	if(n % 2 == 0){
		while(sz(dq) != 0){
			cout << dq.back() << ' ';
			dq.pop_back();
		}
	}
	else {
		while(sz(dq) != 0){
			cout << dq.front() << ' ';
			dq.pop_front();
		}
    }
}