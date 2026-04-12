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
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n ; cin >> n ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	vvll dp(n+1,vll(2,0)) ;
	dp.at(1).at(0) = dp.at(2).at(0) = 0 ;
	dp.at(1).at(1) = a.at(0) ;
	dp.at(2).at(1) = max(a.at(0),a.at(1)) ;
	for(int i=2;i<n;i++){
		if(i&1){
			dp.at(i+1).at(0) = max(dp.at(i).at(0),dp.at(i-1).at(0)+a.at(i)) ;
			dp.at(i+1).at(1) = max(dp.at(i).at(1),dp.at(i-1).at(1)+a.at(i)) ;
		}else{
			dp.at(i+1).at(0) = max(dp.at(i).at(1),dp.at(i-1).at(0)+a.at(i)) ;
			dp.at(i+1).at(1) = dp.at(i-1).at(1)+a.at(i) ;
		}
	}
	cout << dp.at(n).at((n+1)&1) << endl ;
}
