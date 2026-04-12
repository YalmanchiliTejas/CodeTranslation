#include <iostream>
//#include <iomanip>
#include <string>
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
	string s ; cin >> s ;
	ll n = s.size() ;
	ll k ; cin >> k ;
	if(k==1){
		cout << s.at(0)-'0'+9*(n-1) << endl ;
	}else{
		vvll dp0(n,vll(k+1,0)),dp1(n,vll(k+1,0)) ;
		dp0.at(0).at(0) = 1 ;
		dp0.at(0).at(1) = s.at(0)-'0'-1 ;
		dp1.at(0).at(1) = 1 ;
		for(int i=1;i<n;i++){
			for(int j=0;j<=k;j++){
				if(j==0){
					dp0.at(i).at(0) = dp0.at(i-1).at(0)+dp1.at(i-1).at(0)*(s.at(i)!='0') ;
					dp1.at(i).at(0) = dp1.at(i-1).at(0) ;
				}else{
					dp0.at(i).at(j) = dp0.at(i-1).at(j)+dp0.at(i-1).at(j-1)*9+dp1.at(i-1).at(j-1)*(s.at(i)-'0'-(s.at(i)!='0'))+dp1.at(i-1).at(j)*(s.at(i)!='0') ;
					dp1.at(i).at(j) = (s.at(i)=='0'?dp1.at(i-1).at(j):dp1.at(i-1).at(j-1)) ;
				}
			}
		}
		/*for(int j=0;j<=k;j++){
			for(int i=0;i<n;i++){
				cout << dp0.at(i).at(j) << (i==n-1?'\n':' ') ;
			}
		}
		for(int j=0;j<=k;j++){
			for(int i=0;i<n;i++){
				cout << dp1.at(i).at(j) << (i==n-1?'\n':' ') ;
			}
		}*/
		cout << dp0.at(n-1).at(k)+dp1.at(n-1).at(k) << endl ;
	}
}

