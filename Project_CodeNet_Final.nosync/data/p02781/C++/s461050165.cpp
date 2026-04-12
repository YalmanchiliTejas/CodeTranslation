#include <iostream>
//#include <iomanip>
#include <string>
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
//#define all(v) v.begin(),v.end()
//ll mod = 1e9+7 ;
//long double pie = acos(-1) ;
//ll INF = 1e15 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	string s ; cin >> s ;
	ll n = s.size();
	ll k ; cin >> k ;
	vvll dp1(n,vll(k+1,0)),dp2(n,vll(k+1,0)) ;
	dp1.at(0).at(0) = (s.at(0)!='0') ;
	dp1.at(0).at(1) = s.at(0)-'0'-1 ;
	dp2.at(0).at(1) = 1 ;
	for(int i=1;i<n;i++){
		if(s.at(i)=='0'){
			for(int j=0;j<=k;j++) dp2.at(i).at(j) += dp2.at(i-1).at(j) ;
			for(int j=1;j<=k;j++) dp1.at(i).at(j) += dp1.at(i-1).at(j-1)*9 ;
			for(int j=0;j<=k;j++) dp1.at(i).at(j) += dp1.at(i-1).at(j) ;
		}else{
			for(int j=1;j<=k;j++) dp2.at(i).at(j) += dp2.at(i-1).at(j-1) ;
			for(int j=0;j<=k;j++) dp1.at(i).at(j) += dp2.at(i-1).at(j) ;
			for(int j=1;j<=k;j++) dp1.at(i).at(j) += dp2.at(i-1).at(j-1)*(s.at(i)-'0'-1) ;
			for(int j=0;j<=k;j++) dp1.at(i).at(j) += dp1.at(i-1).at(j) ;
			for(int j=1;j<=k;j++) dp1.at(i).at(j) += dp1.at(i-1).at(j-1)*9 ;
		}
	}
	cout << dp1.at(n-1).at(k)+dp2.at(n-1).at(k) << endl ;
//	for(int j=0;j<=k;j++){
//		for(int i=0;i<n;i++) cout << dp1.at(i).at(j) << (i==n-1?"\n":" ") ;
//	}
//	for(int j=0;j<=k;j++){
//		for(int i=0;i<n;i++) cout << dp2.at(i).at(j) << (i==n-1?"\n":" ") ;
//	}
}
