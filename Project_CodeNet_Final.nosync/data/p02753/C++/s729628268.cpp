#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	sort(all(s));
	if (s[0] == 'A' && s[1] == 'A' && s[2] == 'B') cout << "Yes\n";
	else if (s[0] == 'A' && s[1] == 'B' && s[2] == 'B') cout << "Yes\n";
	else cout << "No\n";
	return 0;
}