#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD (1E9+7)
#define PI 3.1415926535897932384

std::ostream &operator<<(std::ostream &out, const vector<int> &tgt)
{
	string s;
	for (int i = 0; i<tgt.size(); i++) {
		s += (to_string(tgt[i]) + ((i != tgt.size() - 1) ? " " : ""));
	}
	out << s;
	return out;
}

ll anl(string s) {
	if (s.size() == 1)return s[0] - '0';
	rep(i, s.size()) {
		if (s[i] == '+') {
			return anl(s.substr(0,i)) + anl(s.substr(i+1));
		}
	}
	rep(i, s.size()) {
		if (s[i] == '*') {
			return anl(s.substr(0, i)) * anl(s.substr(i + 1));
		}
	}
}


bool mtest(string s, ll n) {
	ll ans = anl(s);
	return ans == n;

}

bool ltest(string s, ll n) {
	ll ans = 0;
	ans = s[0] - '0';
	int i = 1;
	range(i,1, s.size()) {
		if (s[i] == '+') {
			ans += s[i + 1]-'0';
		}
		else ans *= s[i + 1]-'0';
		i++;
	}
	return ans == n;
}

void solve(string s, ll n) {
	char c = 'U';
	bool m = mtest(s, n), l = ltest(s, n);
	if (m&&l)c = 'U';
	else if (m)c = 'M';
	else if (l)c = 'L';
	else c = 'I';
	cout << c << endl;
}


int main() {
	string s;
	ll n;
	while (cin >> s) {
		cin >> n;
		solve(s, n);
	}
}
