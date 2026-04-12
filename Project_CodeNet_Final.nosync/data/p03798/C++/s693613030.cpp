#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

int main() {
	ll n; cin >> n;
	string s; cin >> s;
	string t;

	string T[4] = { "SS","SW","WW","WS" };

	rep(k, 0, 4) {
		t = T[k];
		rep(i, 1, s.size() - 1) {
			if (s[i] == 'o') {
				if (t[i] == 'S') {
					if (t[i - 1] == 'S') t += 'S';
					else t += 'W';
				}
				else {
					if (t[i - 1] == 'S') t += 'W';
					else t += 'S';
				}
			}
			else {
				if (t[i] == 'S') {
					if (t[i - 1] == 'S') t += 'W';
					else t += 'S';
				}
				else {
					if (t[i - 1] == 'S') t += 'S';
					else t += 'W';
				}
			}
		}

		//check
		ll x = n - 1;
		bool ok = false;
		if (s[x] == 'o') {
			if (t[x] == 'S') {
				if (t[x - 1] == 'S' && t[0] == 'S') ok = true;
				else if (t[x - 1] == 'W' && t[0] == 'W') ok = true;
			}
			else {
				if (t[x - 1] == 'S' && t[0] == 'W') ok = true;
				else if (t[x - 1] == 'W' && t[0] == 'S') ok = true;
			}
		}
		else {
			if (t[x] == 'S') {
				if (t[x - 1] == 'S' && t[0] == 'W') ok = true;
				else if (t[x - 1] == 'W' && t[0] == 'S') ok = true;
			}
			else {
				if (t[x - 1] == 'S' && t[0] == 'S') ok = true;
				else if (t[x - 1] == 'W' && t[0] == 'W') ok = true;
			}
		}

		x = 0;
		bool ok2 = false;

		if (s[x] == 'o') {
			if (t[x] == 'S') {
				if (t[n - 1] == 'S' && t[1] == 'S') ok2 = true;
				else if (t[n - 1] == 'W' && t[1] == 'W') ok2 = true;
			}
			else {
				if (t[n - 1] == 'S' && t[1] == 'W') ok2 = true;
				else if (t[n - 1] == 'W' && t[1] == 'S') ok2 = true;
			}
		}
		else {
			if (t[x] == 'S') {
				if (t[n - 1] == 'S' && t[1] == 'W') ok2 = true;
				else if (t[n - 1] == 'W' && t[1] == 'S') ok2 = true;
			}
			else {
				if (t[n - 1] == 'S' && t[1] == 'S') ok = true;
				else if (t[n - 1] == 'W' && t[1] == 'W') ok = true;
			}
		}

		if (ok & ok2) {
			cout << t << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}