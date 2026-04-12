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
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	string s ;
	ll k ;
	cin >> s >> k ;
	vvll dp1(s.size()+1,vll(4,0)),dp2(s.size()+1,vll(4,0)) ;
	dp2.at(0).at(0) = 1 ;
	for(int i=1;i<=s.size();i++){
		ll n = s.at(i-1)-'0' ;
		if(n==0){
			dp1.at(i).at(0) = dp1.at(i-1).at(0) ;
			dp1.at(i).at(1) = dp1.at(i-1).at(0)*9+dp1.at(i-1).at(1) ;
			dp1.at(i).at(2) = dp1.at(i-1).at(1)*9+dp1.at(i-1).at(2) ;
			dp1.at(i).at(3) = dp1.at(i-1).at(2)*9+dp1.at(i-1).at(3) ;
			dp2.at(i).at(0) = dp2.at(i-1).at(0) ;
			dp2.at(i).at(1) = dp2.at(i-1).at(1) ;
			dp2.at(i).at(2) = dp2.at(i-1).at(2) ;
			dp2.at(i).at(3) = dp2.at(i-1).at(3) ;
		}else{
			dp1.at(i).at(0) = dp1.at(i-1).at(0)+dp2.at(i-1).at(0) ;
			dp1.at(i).at(1) = dp1.at(i-1).at(0)*9+dp1.at(i-1).at(1)+dp2.at(i-1).at(0)*(n-1)+dp2.at(i-1).at(1) ;
			dp1.at(i).at(2) = dp1.at(i-1).at(1)*9+dp1.at(i-1).at(2)+dp2.at(i-1).at(1)*(n-1)+dp2.at(i-1).at(2) ;
			dp1.at(i).at(3) = dp1.at(i-1).at(2)*9+dp1.at(i-1).at(3)+dp2.at(i-1).at(2)*(n-1)+dp2.at(i-1).at(3) ;
			dp2.at(i).at(0) = 0 ;
			dp2.at(i).at(1) = dp2.at(i-1).at(0) ;
			dp2.at(i).at(2) = dp2.at(i-1).at(1) ;
			dp2.at(i).at(3) = dp2.at(i-1).at(2) ;
		}
	}
//	for(int i=0;i<=s.size();i++){
//		cout << dp1.at(i).at(0) << " " << dp1.at(i).at(1) << " " << dp1.at(i).at(2) << " " << dp1.at(i).at(3) ;
//		cout << " " << dp2.at(i).at(0) << " " << dp2.at(i).at(1) << " " << dp2.at(i).at(2) << " " << dp2.at(i).at(3) << endl ;
//	}
	cout << dp1.at(s.size()).at(k)+dp2.at(s.size()).at(k) << endl ;
}
