#include "bits/stdc++.h"
using namespace std;
int N;
string S;
string ansS;
void solve() {
	for (int i = 1; i < N + 1; ++i) {
		if ('o' == S[i]) {
			if ('S' == ansS[i]) {
				ansS += ansS[i - 1];
			}
			else {
				if ('S' == ansS[i - 1]) {
					ansS += "W";
				}
				else {
					ansS += "S";
				}
			}
		}
		else {
			if ('W' == ansS[i]) {
				ansS += ansS[i - 1];
			}
			else {
				if ('S' == ansS[i - 1]) {
					ansS += "W";
				}
				else {
					ansS += "S";
				}
			}
		}
	}
}
int main() {
	cin >> N;
	cin >> S;
	S += S[0];
	S += S[1];
	string S[] = { "SS","WW","SW","WS" };
	for (int i = 0; i < 4; ++i) {
		ansS = S[i];
		solve();
		if ((ansS[0] == ansS[N])&&(ansS[1] == ansS[N+1])){
			cout << ansS.substr(0,N)<<endl;
			return 0;
		};
	}
	cout << -1 << endl;
	return 0;
}