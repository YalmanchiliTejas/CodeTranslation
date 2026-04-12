#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
const ll mod = 1e9 + 7;
const ll INF = 1e9;
int main() {
	cin.sync_with_stdio(false);
	string S;
	cin >> S;
	rep(i, S.size() - 1) {
		if (S[i] == 'A'&&S[i + 1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}