// C - 怪文書 / Dubious Document
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;

	vector<vector<int>> S(n, vector<int>(26));
	for(int i=0; i<n; i++){
		string s; cin>>s;
		for(auto e:s) S[i][e-'a']++;
	}

	string ans;
	for(int i=0; i<26; i++){
		int mini = 1e9;
		for(int j=0; j<n; j++) if(mini>S[j][i]) mini = S[j][i];
		for(int k=0; k<mini; k++) ans += i+'a';
	}
	cout<< ans <<endl;
}