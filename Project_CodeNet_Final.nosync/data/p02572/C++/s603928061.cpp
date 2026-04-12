#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <ll> vr;
typedef pair <ll, ll> pr;
typedef vector <ll> :: iterator ir;

#define pub push_back
#define pob pop_back
#define mp make_pair
#define pc __builtin_popcount
#define lb lower_bound
#define mod 1000000007

ll dig(ll n) {
	string s = to_string(n);
	return s.size();
}

ll totSum(ll arr[], ll n) {
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif




// write your code here

	int n;
	cin >> n;
	vector<int> arr(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		sum = sum % mod;
	}
	long long result = 0;
	for (int i = 0; i < n; i++) {
		sum = sum - arr[i];
		if (sum < 0)sum += mod;
		result += (sum * arr[i]);
		result = result % mod;
	}
	cout << result;

// this is the end of your code

}
