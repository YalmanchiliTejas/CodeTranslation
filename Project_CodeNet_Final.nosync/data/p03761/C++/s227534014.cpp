#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<map>

#define ipair pair<int,int>
#define rep(n) for(int i=0;i<n;i++)

#define K int('z' - 'a' + 1)

using namespace std;

typedef long long int lli;
typedef vector<int> vi;

int main() {
	int n, i, j;
	int c[K] = {};
	int next_c[K] = {};
	int a = 'a';
	vector<string>s;
	string ans, t;

	cin >> n;

	s.resize(n);

	rep(n) {
		cin >> s[i];
	}
	
	t = s[0];
	rep(t.length()) {
		c[t[i] - a]++;
	}

	rep(n) {
		t = s[i];
		for (j = 0; j < K; j++)
			next_c[j] = 0;
		for (j = 0; j < t.length(); j++) {
			next_c[t[j] - a]++;
		}
		for (j = 0; j < K; j++) {
			c[j] = c[j] > next_c[j] ? next_c[j] : c[j];
		}
	}

	ans = "";

	rep(K) {
		for (j = 0; j < c[i]; j++) {
			ans += char(a + i);
		}
	}

	cout << ans;
	
	return 0;
}