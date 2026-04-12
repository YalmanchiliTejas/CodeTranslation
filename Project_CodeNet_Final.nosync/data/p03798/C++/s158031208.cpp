#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <numeric> //lcm


#define ERROR() cout << "ERROR!!" << endl; return 0;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)

#define debug(vec) for(auto v : vec) cout << v << " "; cout << endl;

#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cout << v << " "; cout << endl; } 

using namespace std;

typedef long long ll;

const long long int INF = 1 << 29; //<10^10
//const ll MOD = 998244353;
const ll MOD = 1000000007;

inline bool maxch(int &a, int b) { if (a < b) {a = b; return true;} else return false;}

int main() {
  int n;
	string s;
	cin >> n >> s;

	rep(a, 2) rep(b, 2) {
		//0:羊,　1:狼
		vector<char> ans(s.size(), '-');
		if (a == 0) ans[0] = 'S'; else ans[0] = 'W';
		if (b == 0) ans[1] = 'S'; else ans[1] = 'W';

		for (int i = 2; i < s.size(); ++i) {
			if (ans[i - 2] == 'S') {
				if (ans[i - 1] == 'S') {
					if (s[i - 1] == 'o') {
					  ans[i] = 'S';
					}
					else {
						ans[i] = 'W';
					}
				}
				else {
					if (s[i - 1] == 'o') {
						ans[i] = 'W';
					}
					else {
					  ans[i] = 'S';
					}
				}
			}
			else {
				if (ans[i - 1] == 'S') {
					if (s[i - 1] == 'o') {
						ans[i] = 'W';
					}
					else {
						ans[i] = 'S';
					}
				}
				else {
					if (s[i - 1] == 'o') {
						ans[i] = 'S';
					}
					else {
						ans[i] = 'W';
					}
				}
			}
		}

		bool ok = true;
		int n = s.size() - 1;
		if (ans[n] == 'S'){
			if (s[n] == 'o') {
				if (ans[n - 1] != ans[0]) ok = false;
			}
			else {
				if (ans[n - 1] == ans[0]) ok = false;
			}
		}
		else {
			if (s[n] == 'o') {
				if (ans[n - 1] == ans[0]) ok = false;
			}
			else {
				if (ans[n - 1] != ans[0]) ok = false;
			}
		}

		if (ans[0] == 'S') {
			if (s[0] == 'o') {
				if (ans[n] != ans[1]) ok = false;
			}
			else {
				if (ans[n] == ans[1]) ok = false;
			}
		}
		else {
			if (s[0] == 'o') {
				if (ans[n] == ans[1]) ok = false;
			}
			else {
				if (ans[n] != ans[1]) ok = false;
			}
		}

		if (ok) {
		  rep(i,n+1) cout << ans[i]; 
			cout << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}


