#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define INF 1000000000

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(x) begin(x), end(x)
#define len(x) ((int)(x).size())
#define contains(a, x) (a.find(x) != end(a))
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); ++i)
#define RF(i,a,b)for(int i = (int)(a); i >= (int)(b); --i)

using dbl = double;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvl = vector<long long>;
using pi = pair<int,int>;

#define log(x) cout << x << endl;
#define fast() {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}


int main() {
	int n;
	cin >> n;
	string s;

	set<char> chars;
	map<char,int> freq, fq, mn;

	rep (i, n) {
		cin >> s;
		chars={}, fq={};

		for (auto c: s)
			chars.emplace(c), fq[c] += 1;

		for (auto c: chars)
			freq[c] += 1;

		for (auto c: chars) {
			if (mn[c]==0) mn[c] = fq[c];
			else mn[c] = min(mn[c], fq[c]);
		}
	}

	string r = "";
	for (char c='a'; c<'a'+26; ++c) {
		if (freq[c] == n) {
			for (int i=0; i<mn[c]; ++i) r += c;
		}
	}

	log(r)

	return 0;
}


