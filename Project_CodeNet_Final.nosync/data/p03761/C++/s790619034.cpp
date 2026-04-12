#include"bits/stdc++.h"
using namespace std;

const int INF=(int)1e9;

int main() {
	int n;
	cin >> n;
	vector<string> S(n);
	for(int i=0; i<n; i++) cin >> S[i];
	
	map<char,int> m,mm[55];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < S[i].length(); j++) {
			m[S[i][j]]++;
			mm[i][S[i][j]]++;
		}
	}
	vector<char> chs;
	for (auto itr = m.begin(); itr != m.end(); itr++) {
		if(itr->second!=1 || n==1) chs.push_back(itr->first);
	}
	map<char,int> ansm;
	for(int i=0; i<chs.size(); i++) ansm[chs[i]]=INF;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < chs.size(); j++) {
			ansm[chs[j]] = min(ansm[chs[j]],mm[i][chs[j]]);
		}
	}
	for (auto itr = ansm.begin(); itr != ansm.end(); itr++) {
		//cout << itr->first <<" "<< itr->second << endl;
		for (int i = 0; i < itr->second; i++) {
			cout << itr->first;
		}
	}
	cout << endl;
}