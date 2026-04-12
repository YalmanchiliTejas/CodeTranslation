#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n ; cin >> n ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	sort(all(a)) ;
	if(n&1){
		ll r1,r2 ;
		r1 = r2 = 0 ;
		for(int i=0;i<n;i++){
			if(i<=n/2) r1 -= 2*a.at(i) ;
			else r1 += 2*a.at(i) ;
			if(i<n/2) r2 -= 2*a.at(i) ;
			else r2 += 2*a.at(i) ;
		}
		r1 += a.at(n/2)+a.at(n/2-1) ;
		r2 -= a.at(n/2)+a.at(n/2+1) ;
		cout << max(r1,r2) << endl ;
	}else{
		ll ans = 0 ;
		for(int i=0;i<n;i++){
			if(i<n/2) ans -= 2*a.at(i) ;
			else ans += 2*a.at(i) ;
		}
		ans += a.at(n/2-1) ;
		ans -= a.at(n/2) ;
		cout << ans << endl ;
	}
}
