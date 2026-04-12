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
//using ll = long long ;
//using ld = long double ;
//using vll = vector<ll> ;
//using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
using vb = vector<bool> ;
using vvb = vector<vb> ;
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
	int h,w ;
	cin >> h >> w ;
	vvc g(h+2,vc(w+2,'.')) ;
	vvb ok(h+2,vb(w+2,true)) ;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin >> g.at(i).at(j) ;
			if(g.at(i).at(j)=='#'){
				ok.at(i).at(j) = false ;
			}
		}
	}
	int posi,posj ;
	posi = posj = 1 ;
	while(1){
		ok.at(posi).at(posj) = true ;
		if(ok.at(posi+1).at(posj)&&ok.at(posi).at(posj+1)) break ;
		if(!ok.at(posi).at(posj+1)){
			posj++ ;
		}else{
			posi++ ;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(!ok.at(i).at(j)){
				cout << "Impossible" << endl ;
				return 0 ;
			}
		}
	}
	cout << "Possible" << endl ;
}
