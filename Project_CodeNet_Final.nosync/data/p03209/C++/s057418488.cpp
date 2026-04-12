#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

#define REP(i,n) for(int i=0; i<n; i++)
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
 
#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9

using namespace std;
typedef long long ll;

int main(){
	int n;
	ll x, ans = 0;
	cin >> n >> x;
	
	ll burger = pow(2,n+1) - 1 + pow(2, n+1) - 2;
	ll patty = pow(2, n+1)-1;
//
//	debug(burger);
//	debug(patty);
	
	REP(i,n+1){
		burger = (burger+1)/2;
		patty = patty/2;
//		debug(burger);
//		debug(patty);
		if (x >= burger){
			ans += patty+1;
			x -= (burger-1);
//			debug(x);
		}else{
			burger -= 1;
			x -= 1;
		}
	}
	
	cout << ans << endl;
	return 0;
}
