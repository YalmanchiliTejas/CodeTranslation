#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n,x,m;
	cin >> n >> x >> m;
	
	set<ll> s;
	vector<ll> his;
	ll ans = 0;
	ll a = x;
	ll count;
	s.insert(a);
	ans += a;
	his.push_back(a);
	for(int i=2; i<=m+1; i++){
		a = a*a%m;
		if(a==0){
			cout << ans << endl;
			return 0;
		}
		
		auto it = s.find(a);
		
		if(it == s.end()){
			s.insert(a);
			ans += a;
			his.push_back(a);
		}else{
			count = i-1;
			break;
		}
		if(i == n){
			cout << ans << endl;
			return 0;
		}
	}
	
	ll prev=0,pnum=0;
	for(auto x: his){
		if(x!=a){
			prev += x;
			pnum++;
		}else{
			break;
		}
	}
	
	ll loop = ans - prev;
	vector<ll> sum;
	sum.push_back(0);
	FOR(i, pnum, his.size()){
		sum.push_back(sum.back()+his[i]);
	}
	
	ans = prev + loop*((n-pnum)/(count-pnum)) + sum[(n-pnum)%(count-pnum)];
	
	cout << ans << endl;
	
	return 0;
}