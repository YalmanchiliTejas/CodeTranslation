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
//using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<string> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,x ;
	cin >> n >> x ;
	vector<ll> b(n+1,1) ;
	vector<ll> p(n+1,1) ;
	for(int i=1;i<=n;i++){
		b.at(i) = b.at(i-1)*2+3 ;
		p.at(i) = p.at(i-1)*2+1 ;
	}
	ll ans = 0 ;
	ll level = n ;
	while(1){
		if(level==1){
			if(x<=4) ans += x-1 ;
			else ans += 3 ;
			break ;
		}
		if(x==1) break ;
		if(x==b.at(level)){
			ans += p.at(level) ;
			break ;
		}
		if(x==(b.at(level)+1)/2){
			ans += p.at(level-1)+1 ;
			break ;
		}
		if(x>(b.at(level)+1)/2){
			ans += p.at(level-1)+1 ;
			x -= b.at(level-1)+2 ;
			level-- ;
		}else{
			x -= 1 ;
			level-- ;
		}
	}
	cout << ans << endl ;
}
