#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <complex>
 
 
using namespace std;
 
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
 
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int MOD =  1e9 + 7; 
 
 
 
ll power(ll a, ll b){
	if(b == 0) return 1;
	else {
		ll x = power(a,b/2);
		x = (x*x)%MOD;
		if(b&1) return (x*a)%MOD;
		else return x;
	}
}
 
 
ll& Mod(ll& a) {
    if (a >= MOD) {
        return Mod(a -= MOD);
    } else if (a < 0) {
        return Mod(a += MOD);
    } else {
        return a;
    }
}
 
ll gcd(ll a, ll b) { 
	// b < a
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
 



int main() {
	fast_cin();	
	

	string n; 
	cin >> n;
	int dig; cin >> dig;
	ll ans;
	if(dig == 3){
		 ans = ((((ll)n.size() - 1)*(n.size() - 2)*(n.size() - 3))/6)*9*9*9 + ((n[0] - '0') - 1)* (((ll)n.size() - 1) * (n.size() - 2)/2)*9*9;
		string num = "";
		num += n[0];
		for(int i = 1; i < n.size(); i++) num += "0";
		
		
		for(int j = 1; j < n.size(); j++){
			for(int k = j+1; k < n.size(); k++){
				for(int nj = 1; nj <= 9; nj++){
					for(int nk = 1; nk <= 9; nk++){
						num[j] = to_string(nj)[0];
						num[k] = to_string(nk)[0];
						if(num <= n){
							ans++;
						}
						num[j] = '0';
						num[k] = '0';
					}
				}
			}
		}
		
		
	}
	if(dig == 2){
		 ans = (((ll)n.size() - 1)*(n.size() - 2)/2)*9*9 + ((ll)n.size() - 1)*9*((n[0] - '0') - 1);
		 debug(ans);
		string num = "";
		num += n[0];
		for(int i = 1; i < n.size(); i++) num += "0";
		
		for(int i = 1; i < n.size(); i++){
			for(int ni = 1; ni <= 9; ni++){
				num[i] = to_string(ni)[0];
				if(num <= n){
					ans++;
				}
				num[i] = '0';
			}
		}
	}
	if(dig == 1){
		 ans = ((ll)n.size() - 1)*9 + (n[0] - '0');
	}
	
	cout << ans << '\n';
	
		
		
		
		
	
		
}
