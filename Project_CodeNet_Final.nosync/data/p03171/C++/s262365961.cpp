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
//void fix_cout(){cout << fixed << setprecision(20) ;}
//void chmin(ll &a,ll b){if(a>b) a = b ;}

ll n ;

ll solve(vll &a,vvll &dp,ll l,ll r){
	if(l==r){
		dp.at(l).at(r) = 0 ;
		return 0 ;
	}
	if(dp.at(l).at(r)!=-1) return dp.at(l).at(r) ;
	if((n-r+l+1)&1){
		dp.at(l).at(r) = max(solve(a,dp,l+1,r)+a.at(l),solve(a,dp,l,r-1)+a.at(r-1)) ;
	}else{
		dp.at(l).at(r) = min(solve(a,dp,l+1,r)-a.at(l),solve(a,dp,l,r-1)-a.at(r-1)) ;
	}
	return dp.at(l).at(r) ;
}

int main(){
	cin >> n ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	vvll dp(n+10,vll(n+10,-1)) ;
	cout << solve(a,dp,0,n) << endl ;;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout << dp.at(i).at(j) << (j==n-1?'\n':' ') ;
//		}
//	}
}
