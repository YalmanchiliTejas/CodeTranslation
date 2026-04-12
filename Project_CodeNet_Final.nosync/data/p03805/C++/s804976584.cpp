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

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 10000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,m ;
	cin >> n >> m ;
	vvll g(n,vll(n,0)) ;
	for(int i=0;i<m;i++){
		ll a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		g.at(a).at(b) = g.at(b).at(a) = 1 ;
	}
	vll num(n-1) ;
	ll ans = 0 ;
	for(int i=0;i<n-1;i++) num.at(i) = i+1 ;
	do{
		vll p(n) ;
		p.at(0) = 0 ;
		for(int i=0;i<n-1;i++){
			p.at(i+1) = num.at(i) ;
		}
		bool ok = true ;
		for(int i=0;i<n-1;i++){
			if(g.at(p.at(i)).at(p.at(i+1))) continue ;
			ok = false ;
		}
		ans += ok ;
	}while(next_permutation(num.begin(),num.end())) ;
	cout << ans << endl ;
}
