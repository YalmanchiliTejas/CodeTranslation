#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
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
using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;

ll mod = 998244353 ;
//long double pie = acos(-1) ;

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,s ;
	cin >> n >> s ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	vvll dp(n+1,vll(3001,0)) ;
	for(int i=1;i<=n;i++){
		dp.at(i).at(0) = i ;
		dp.at(i).at(a.at(i-1)) = 1 ;
		for(int j=1;j<=s;j++){
			dp.at(i).at(j) += dp.at(i-1).at(j) ;
			if(a.at(i-1)<=j) dp.at(i).at(j) += dp.at(i-1).at(j-a.at(i-1)) ;
			dp.at(i).at(j) %= mod ;
		}
	}
	ll ans = 0 ;
	for(int i=1;i<=n;i++) ans = (ans+dp.at(i).at(s))%mod ;
	cout << ans << endl ;
}
