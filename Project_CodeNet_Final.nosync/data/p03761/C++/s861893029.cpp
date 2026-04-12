#include<bits/stdc++.h>
using namespace std;

string compare(string S, string A) {
    string X;
	for (int i = 0; i < S.size(); i++) {
		if (A.find(S[i])!=-1) {
			A.erase(A.find(S[i]),1);
			X+=S[i];
		}
	}

	return X;
}




int main() {
	int n;
	cin >> n;

	string S, A;
	cin >> S;

	for (int i = 0; i < n - 1; i++) {
		cin >> A;

		S = compare(S, A);
	}
    
    sort(S.begin(),S.end());
	cout << S << endl;
}