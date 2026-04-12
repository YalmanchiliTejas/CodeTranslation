//17571@nith.ac.in @Ankit Verma
#include <bits/stdc++.h>
#define bolt ios::sync_with_stdio(false)
#define ull unsigned long long
#define ll long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
using namespace std;

int main() {

/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
#endif*/

	bolt;
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s; cin >> s;
	int cnt1 = 0; int cnt2 = 0;
	for (int i = 0; i < 3; i++){
		if (s[i] == 'A') {
			cnt1++;
		} else {
			cnt2++;
		}
	}
	if (cnt1 > 0 && cnt2 > 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	

	return 0;
}