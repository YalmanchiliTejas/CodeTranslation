#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using IP = pair<int, int>;


#define INF 999999999
#define atcoder(int)1e9+7
#define Endl endl
#define all(v) (v.begin(),v.end())
#define pb(a) push_back(a)

int main() {

	string s;

	cin >> s;

	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			cout << "Yes" << Endl;
			return 0;
		}
	}
	cout << "No" << Endl;

	return 0;
}