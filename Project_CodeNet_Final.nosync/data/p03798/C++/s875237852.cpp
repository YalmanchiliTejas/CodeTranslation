#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>

#define	MOD 1000000007;
#define PI 3.14159265358979323846;
#define rep(i,n) for(ll i = 0;i<(ll)n;i++)
using namespace std;
typedef long long ll;
static const int MAX = 50;
static const long long INFTYL = 9223372036854775807;
ll mod = 1000000007;

int main()
{
	ll N;
	string s;
	cin >> N >> s;

	string t;

	vector<string> T = { "SS","SW","WW","WS" };
	for (vector<string>::iterator it = T.begin(); it != T.end(); it++)
	{
		t = *it;

		rep(i, s.size() - 1) {
			if (i == 0) {
				continue;
			}
			if (s[i] == 'o') {
				if (t[i] == 'S') {
					t += t[i - 1];//i+2
				}
				else {
					t += t[i - 1] == 'S' ? 'W' : 'S';//i+2
				}
			}
			else {
				if (t[i] == 'S') {
					t += t[i - 1] == 'S' ? 'W' : 'S';//i+2
				}
				else {
					t += t[i - 1];//i+2
				}
			}
		}
		bool valid_1 = false;
		bool valid_L = false;
		ll l = t.size() - 1;
		if (t[0] == 'S') {
			valid_1 = (s[0] == 'o' && t[1] == t[l] || s[0] == 'x' && t[1] != t[l]);
		}
		else {//t[i] == 'W'
			valid_1 = (s[0] == 'o' && t[1] != t[l] || s[0] == 'x' && t[1] == t[l]);
		}

		if (t[l] == 'S') {
			valid_L = (s[l] == 'o' && t[0] == t[l - 1] || s[l] == 'x' && t[0] != t[l - 1]);
		}
		else {//t[i] == 'W'
			valid_L = (s[l] == 'o' && t[0] != t[l - 1] || s[l] == 'x' && t[0] == t[l - 1]);
		}

		if (valid_1 && valid_L) {
			cout << t << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}