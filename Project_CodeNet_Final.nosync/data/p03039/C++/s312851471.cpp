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
//#define all(v) v.begin(),v.end()
ll mod = 1e+9+7;
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

ll modpow(ll a,ll b){
	ll res = 1 ;
	while(b>0){
		if(b&1) res = res*a%mod ;
		b >>= 1 ;
		a = a*a%mod ;
	}
	return res ;
}

int main(){
	vll sum(200010,0) ;
	for(int i=1;i<sum.size();i++) sum.at(i) = (sum.at(i-1)+i)%mod ;
	vll fac(200010,1) ;
	for(int i=2;i<fac.size();i++) fac.at(i) = fac.at(i-1)*i%mod ;
	ll n,m,k ;
	cin >> n >> m >> k ;
	ll ans = 0 ;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans += (sum.at(j-1)+sum.at(m-j))%mod*n%mod ;
			ans %= mod ;
			ans += (sum.at(i-1)+sum.at(n-i))%mod*m%mod ;
			ans %= mod ;
//			cout << ans << endl ;
		}
	}
	ans = ans*modpow(2,mod-2)%mod ;
	ll nm = 1 ;
	for(int i=0;i<k-2;i++) nm = nm*(n*m-2-i)%mod ;
	cout << ans*nm%mod*modpow(fac.at(k-2),mod-2)%mod << endl ;
}
