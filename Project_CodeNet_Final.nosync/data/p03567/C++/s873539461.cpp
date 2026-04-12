#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;
const int INF = 1 << 25;
const LL MOD = 1000000007LL;
using namespace std;
int main() {
	string S;
	cin >> S;
	for (int i = 0; i + 1 < S.size(); i++) {
		if (S.substr(i, 2) == "AC") {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}