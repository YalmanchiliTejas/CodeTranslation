#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <set>
using namespace std;

void setIn(string s){freopen(s.c_str(), "r", stdin);}
void setOut(string s){freopen(s.c_str(), "w", stdout);}
void unsyncIO(){cin.tie(0) -> sync_with_stdio(0);}
void setIO(string s = ""){
	unsyncIO();
	if(s.size()){
		setIn(s + ".in");
		setOut(s + ".out");
	}
}


#define ll long long
const ll mod = 1e9 + 7;
const int MX = 5005;

int main(){
	setIO();
	int n;
	cin >> n;
	vector<ll> v(n), suff(n + 1, 0ll);
	for(int i =0 ; i < n; i ++) cin >> v[i];
	for(int i = n- 1; i >= 0; i --)
		suff[i] = (suff[i + 1] + v[i]) % mod;

	ll ans = 0ll;
	for(int i = 0; i < n; i ++)
		ans = (ans + (suff[i + 1] * 1ll * v[i] ) % mod) % mod;
	cout << ans << endl;
}