#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
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
//using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,x ;
	cin >> n >> x ;
	vll b(n+1),p(n+1) ;
	b.at(0) = 1 ; p.at(0) = 1 ;
	for(int i=1;i<n+1;i++){
		b.at(i) = 2*b.at(i-1)+3 ;
		p.at(i) = 2*p.at(i-1)+1 ;
	}
	ll ans = 0 ;
	x-- ;
	for(int i=n;i>0;i--){
		if(i==1){
			if(x==1) ans++ ;
			if(x==2) ans += 2 ;
			if(x==3||x==4) ans += 3 ;
			break ;
		}
		if(x==0) break ;
		if(x>=b.at(i)-1){
			ans += 2*p.at(i-1)+1 ;
			break ;
		}
		if(x==1+b.at(i-1)){
			ans += p.at(i-1)+1 ;
			break ;
		}else{
			if(x>1+b.at(i-1)){
				ans += p.at(i-1)+1 ;
				x -= b.at(i-1)+2 ;
			}else{
				x -= 1 ;
			}
		}
	}
	cout << ans << endl ;
}
