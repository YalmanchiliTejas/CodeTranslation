#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

#define for0(i, n) for (ll i = 0; i < (ll)(n); ++i) // 0 based indexing
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (ll i = (ll)(l); i <= (ll)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (ll i = (ll)(n); i >= 1; --i) // reverse 1 based

#define ff first
#define ss second
#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	if(s[0] != s[1] || s[1] != s[2]){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}