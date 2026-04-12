#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9+7;

ll bd[10000][100], d;
string s;

int main() {
	getline(cin, s);
	cin >> d;
	memset(bd, 0, sizeof(bd));
	bd[0][0] = 1;
	for (int i=1; i<s.length(); i++) {
		for (int j=0; j<10; j++) {
			bd[i][0] += bd[i-1][(10*d-j)%d];
			bd[i][0] %= M;
		}
		for (int j=1; j<d; j++) {
			bd[i][j] = bd[i][j-1]+bd[i-1][j]-bd[i-1][(j-10+10*d)%d]+M;
			bd[i][j] %= M;
		}
	}
	ll cnt = 0;
	ll sum = 0;
	for (int i=0; i<s.length(); i++) {
		for (int j=0; j<s[i]-'0'; j++) {
			cnt += bd[s.length()-1-i][((-sum-j)%d+d)%d];
			cnt %= M;
		}
		sum += s[i]-'0';
	}
	cnt += bd[0][sum%d];
	cout << (cnt-1+M)%M << "\n";
}