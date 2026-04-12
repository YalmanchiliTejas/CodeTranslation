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
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;\

//ll mod = 1000000007 ;
//ll INF = 10000000000 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}


int main(){
	ll n ; cin >> n ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	bool ok = true ;
	ll cnt = 0 ;
	while(ok){
		ok = false ;
		ll sum = 0 ;
		for(int i=0;i<n;i++){
			if(a.at(i)>=n){
				sum += a.at(i)/n ;
			}
		}
		ok = (sum!=0) ;
		if(ok){
			cnt += sum ;
			for(int i=0;i<n;i++){
				a.at(i) += (sum-a.at(i)/n)-a.at(i)/n*n ;
			}
		}
	}
	cout << cnt << endl ;
}
