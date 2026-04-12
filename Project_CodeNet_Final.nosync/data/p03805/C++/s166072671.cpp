#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
ll INF = 1ll<<61 ;

void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
void fix_cout(){cout << fixed << setprecision(20) ;}
void chmax(ll &a,ll b){	if(a<b) a = b ;}
void chmin(ll &a,ll b){ if(a>b) a = b ;}

int main(){
	int n,m ;
	cin >> n >> m ;
	vector<vector<bool>> e(n,vector<bool>(n,false)) ;
	for(int i=0;i<m;i++){
		int a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		e.at(a).at(b) = e.at(b).at(a) = true ;
	}
	vector<int> num ;
	for(int i=0;i<n;i++) num.push_back(i) ;
	int ans = 0 ;
	do{
		if(num.at(0)!=0) break ;
		bool ok = true ;
		for(int i=1;i<n;i++) ok &= e.at(num.at(i-1)).at(num.at(i)) ;
		ans += ok ;
	}while(next_permutation(all(num))) ;
	cout << ans << endl ;
}
