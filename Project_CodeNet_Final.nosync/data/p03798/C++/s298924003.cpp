#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<string, string> sP;
typedef pair<ll, pair<ll, ll>> PP;

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second


char c[2] = { 'S','W' };

int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int y = 0;y < 2;y++) {
		for (int z = 0;z < 2;z++) {
			string t;
			t += c[y];
			t += c[z];
			for (int i = 1;i < n-1;i++) {
				if (t[i] == 'S'&&t[i - 1] == 'S') {
					if (s[i] == 'o')t+='S';
					else t+= 'W';
				}
				else if (t[i] == 'S'&&t[i - 1] == 'W') {
					if (s[i] == 'o')t+='W';
					else t+='S';
				}
				else if (t[i] == 'W'&&t[i - 1] == 'S') {
					if (s[i] == 'o')t+='W';
					else t+= 'S';
				}
				else {
					if (s[i] == 'o')t += 'S';
					else t+= 'W';
				}
			}
			bool fl = 0;
			if (t[n - 1] == 'S') {
				if (s[n - 1] == 'o') {
					if (t[n - 2] == t[0])fl = 1;
				}
				else {
					if (t[n - 2] != t[0])fl = 1;
				}
			}
			else {
				if (s[n - 1] == 'o') {
					if (t[n - 2] != t[0])fl = 1;
				}
				else {
					if (t[n - 2] == t[0])fl = 1;
				}
			}

			if (fl) {
				if (t[0] == 'S') {
					if (s[0] == 'o') {
						if (t[n - 1] == t[1]) {
							cout << t << endl;
							return 0;
						}
					}
					else {
						if (t[n - 1] != t[1]) {
							cout << t << endl;
							return 0;
						}
					}
				}
				else {
					if (s[0] == 'o') {
						if (t[n - 1] != t[1]) {
							cout << t << endl;
							return 0;
						}
					}
					else {
						if (t[n - 1] == t[1]) {
							cout << t << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}