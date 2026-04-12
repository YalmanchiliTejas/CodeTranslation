#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9;
const ll lINF = 1e18;
const int MOD = 1e9+7;
const int SIZE = 100;


int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length()-1; i++) {
		if (s[i] == 'A' && s[i+1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
