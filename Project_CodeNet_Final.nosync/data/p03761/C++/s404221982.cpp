#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(26,1e9);
	for (int i = 0; i < N; ++i) {
		vector<int>Asub(26);
		string S;
		cin >> S;
		for (int j = 0;j<S.size();++j) {
			Asub[S[j]-'a']++;
		}
		for (int j = 0;j<26;++j) {
			A[j] = min(A[j],Asub[j]);
		}
	}
	string ans;
	for (int i = 0;i<26;++i) {
		for (int j = 0;j<A[i];++j) {
			ans += (char)('a'+i);
		}
	}
	cout << ans<<endl;
	return 0;
}