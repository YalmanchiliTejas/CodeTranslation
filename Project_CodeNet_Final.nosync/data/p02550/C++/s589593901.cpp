#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <random>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <tuple>
#include <math.h>
#include <set>
#include <map>
using namespace std ;
using ll = long long ;
using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
using vb = vector<bool> ;
using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end() 
const ll INF = 1e18 ;
const ll mod = 998244353 ;
const double pie = acos(-1); 
vll dx4 = {-1,0,1,0} ;
vll dy4 = {0,-1,0,1} ;
vll dx8 = {-1,0,1,1,1,0,-1,-1} ;
vll dy8 = {-1,-1,-1,0,1,1,1,0} ; 

void fix_cout(){cout << fixed << setprecision(20) ; }
ll gcd(ll a,ll b){if(b==0) return a ; return gcd(b,a%b) ; }
ll lcm(ll a,ll b){return a/gcd(a,b)*b ; }
void chmax(ll &a,ll b){if(a<b) a = b ; }
void chmin(ll &a,ll b){if(a>b) a = b ; }

int main(){
	ll n,x,m ;
	cin >> n >> x >> m ;
	if(n<=1e6){
		ll ans = 0 ;
		for(int i=1;i<=n;i++){
			ans += x ;
			x = x*x%m ;
		}
		cout << ans << endl ;
		return 0 ;
	}
	vll rem ;
	ll ans = 0 ;
	ll last ;
	vector<bool> use(m,false) ;
	for(int i=1;i<=m+10;i++){
		if(x==0){
			cout << ans << endl ;
			// cout << "zero" << endl ;
			return 0 ;
		}
		last = x ;
		if(use[x]) break ;
		ans += x ;
		rem.push_back(x) ;
		use[x] = true ;
		x = x*x%m ;
	}
	ans = 0 ;
	ll pos = 0 ;
	for(int i=0;i<rem.size();i++){
		if(last!=rem[i]){
			ans += rem[i] ;
			n-- ;
			pos++ ;
		}else{
			break ;
		}
	}
	ll sum=0,cnt=0 ;
	for(int i=pos;i<rem.size();i++){
		sum += rem[i] ;
		cnt++ ;
	}
	ans += n/cnt*sum ;
	n %= cnt ;
	for(int i=0;i<n;i++) ans += rem[pos+i] ;
	cout << ans << endl ;
}