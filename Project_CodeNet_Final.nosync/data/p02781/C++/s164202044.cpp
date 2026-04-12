#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
// using namespace __gnu_pbds;
using namespace std;
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef long double ld;
typedef pair<long long ,long long> ii; 	
//typedef complex<long double> com;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string n;
	cin >> n;
	ll k;
	ll c = 0;
	cin >> k;
	ll ans = 0;
	ll t;
	t = n.size();
	if (k == 1){
		cout << (t-1)*9+n[0]-'0' << endl;
	}
	else if (k == 2){
		if (t < 2){
			cout << 0 << endl;
			return 0;
		}
		ans += (t-1)*(t-2)/2*ll(9*9);
		ans += max(ll(0),ll(n[0]-'0'-1))*(t-1)*9;
		ll c = 0;
		c++;
		t--;
		while (n[c] == '0' && c < n.size()){
			c++;
			t--;
		}
		if (c == n.size()){
			cout << ans << endl;
			return 0;
		}
		ans += (t-1)*9+n[c]-'0';
		cout << ans << endl;
	}
	else if (k == 3){
		if (t < 3){
			cout << 0 << endl;
			return 0;
		}
		ans += (t-1)*(t-2)*(t-3)/ll(6)*ll(9*9*9);
		ans += max(ll(0),ll(n[0]-'0'-1))*(t-1)*(t-2)/2*ll(9*9);
		ll c = 0;
		c++;
		t--;
		while (n[c] == '0' && c < n.size()){
			c++;
			t--;
		}
		if (c == n.size()){
			cout << ans << endl;
			return 0;
		}
		ans += (t-1)*(t-2)/2*ll(9*9);
		ans += max(ll(0),ll(n[c]-'0'-1))*(t-1)*9;
		c++;
		t--;
		while (n[c] == '0' && c < n.size()){
			c++;
			t--;
		}
		if (c == n.size()){
			cout << ans << endl;
			return 0;
		}
		ans += (t-1)*9+n[c]-'0';
		cout << ans << endl;
	} 
	
} 
 