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
#include <cassert>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i,n) cin >> a[i];
	sort(a.begin(), a.end());
	
	ll res=0;
	{
		vector<int> ans(n,-1);
		int index=0;
		FOR(i,1,n){
			if(i%2==1){
				ans[i] = a[index];
				index++; 
			}
		}
		ans[0] = a[index];
		index++;
		for(int i=n-1; i>0; i--){
			if(i%2==0){
				ans[i] = a[index];
				index++; 
			}
		}
		REP(i,n-1) res += abs(ans[i]-ans[i+1]);
	}
	{
		vector<int> ans(n,-1);
		int index=n-1;
		FOR(i,1,n){
			if(i%2==1){
				ans[i] = a[index];
				index--; 
			}
		}
		ans[0] = a[index];
		index--;
		for(int i=n-1; i>0; i--){
			if(i%2==0){
				ans[i] = a[index];
				index--; 
			}
		}
		ll r = 0;
		REP(i,n-1) r += abs(ans[i]-ans[i+1]);
		chmax(res, r);
	}
	
	cout << res << endl;
	
	
	return 0;
}