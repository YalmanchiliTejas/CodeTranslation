#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, h;

int main(){
	cin >> n;
	ll maxh = 0;
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		cin >> h;
		if(h >= maxh){ans++;}
		maxh = max(h, maxh);
	}
	cout << ans << endl;
	return 0;
}