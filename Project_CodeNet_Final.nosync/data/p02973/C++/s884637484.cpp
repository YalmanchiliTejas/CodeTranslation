#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,int>
#define pli std::pair<ll,int>
#define pil std::pair<int,ll>
#define psi std::pair<string,int>
#define pll std::pair<ll,ll>
#define pci std::pair<char,int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define pb push_back
#define vll std::vector<ll>
#define vpi std::vector<std::pair<int,int>>
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define vvpil std::vector<std::vector<std::pair<int,ll>>>
#define vlpii std::vector<std::list<pii>>
#define vlpil std::vector<std::list<pil>>
#define li std::list<int>
#define lpil std::list<pil>
#define Endl printf("\n")
#define vli vector<list<int>>
#define vvll vector<vector<ll>>
#define mp make_pair
#define x first
#define y second
#define ma 100000000
#define imie(...) "[" << #__VA_ARGS__": " << (__VA_ARGS__) << "] "
const ll  INF=10000000000000;
const ll mod = 1000000007;
using namespace std;
void add(ll& x , ll y){
	x += y;
	if(x >= mod) x -= mod;
}
ll mul(ll x , ll y){
	return (x * y) % mod;
}
ll Pow(ll x , ll y){
	if(y == 0) return 1 ;
	ll z = Pow(x , y / 2) ;
	if(y % 2) return (((z * z) % mod) * x) % mod ;
	return (z * z) % mod  ;
}
bool f(string x , string y){
	string c = x + y ;
	string d = y + x ;
	vll h(c.size() , 0) ;
	h[0] = (c[0] == 'h') ;
	for(int i = 1 ; i < (int)c.size() ; i++){
		h[i] = h[i - 1] + (c[i] == 'h') ;
	}
	vll h1(c.size() , 0) ;
	h1[0] = (d[0] == 'h') ;
	for(int i = 1 ; i < (int)c.size() ; i++){
		h1[i] = h1[i - 1] + (d[i] == 'h') ;
	}
	ll ans1 = 0 ;
	for(int i = 0 ; i < (int)c.size() ; i++){
		if(c[i] == 's')
			ans1 += h[(int)c.size() - 1] - h[i] ;
	}
	ll ans2 = 0 ;
	for(int i = 0 ; i < (int)c.size() ; i++){
		if(d[i] == 's')
			ans2 += h1[(int)c.size() - 1] - h1[i] ;
	}
	return ans1 >  ans2 ;
}
//Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
///    *check mod
///    *check input file  
int main(){
	IOS;
	int n ; cin >> n ;
	vll a(n) ; for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	vll col = {a[n -1]} ;
	for(int i = n - 2 ; i >= 0 ; i--){
		vll :: iterator up = upper_bound(col.begin() , col.end() , a[i]) ;
		if(up == col.end()) col.pb(a[i]) ;
		else *up = a[i] ;
	}
	cout << col.size() << endl ;
	
	
			
	
	return 0;
}

