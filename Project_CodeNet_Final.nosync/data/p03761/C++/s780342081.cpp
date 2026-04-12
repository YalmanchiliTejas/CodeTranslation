#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> alp(26);
	string S;
	cin >> S;
	for (char c : S) alp[c-'a']++;
	rep(i,n-1) {
		cin >> S;
		vector<int> tmp(26);
		for (char c : S) tmp[c-'a']++;
		rep(j,26) alp[j] = min(alp[j],tmp[j]);
	}

	rep(i, 26) {
		rep(j,alp[i]) {
			cout << (char)(i+'a');
		}
	}
	cout << endl;
	return 0;
}