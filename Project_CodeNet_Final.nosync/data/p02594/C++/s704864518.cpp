/******************************************
* nils sjoberg never died  *
* He hibernated *
* So did dinesh easwar *
******************************************/
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <iomanip>
 
using namespace std;
typedef vector< long long > vec;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define pb push_back
#define PB pop_back()
#define sqr(a) (((a) * (a)))
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define umap unordered_map
#define all(c) (c).begin(),(c).end()
#define newl "\n"
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a; i>=b; i--)
#define forn(i, n) for (ll i = 0; i < n; i++)
#define sz(a) int((a).size())
#define frev(n) for(ll i=n-1; i>=0, i--)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
#define vecpresent(container, element) (find(all(container), element) != container.end())
#define N 1000000007
#define PI 3.1415926535897932384
#define F first
#define S second
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll binpow(ll a, ll b, ll m){
	a %= m;
	ll res = 1;
	while(b>0){
	if(b&1)
		res = res * a % m;
	a = a * a % m;
	b >>= 1;
	}
	return res;
}

ll binmul(ll a, ll b, ll m){
	b %= m;
	ll res = 0;
	while(a>0){
		if(a&1)
			res = res + b % m;
		b = b + b % m;
		a >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

pii fib(int n){
	if(n==0)
		return {0, 1};
	auto p = fib(n >> 1);
	int c = p.first * (2*p.second - p.first);
	int d = p.first*p.first + p.second*p.second;
	if(n&1)
		return {d, c+d};
	else
		return {c, d};
}


 
void solve(){
	ll n; cin >> n;
	if(n<30) cout<<"No";
	else cout<<"Yes";

	
}



int main()
{
 	FAST
	ll test;
	test=1;
	//cin>>test;
	while(test--)
	{
		solve();
	}
	return 0;
}

