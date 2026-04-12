#include<bits/stdc++.h>

using namespace std;

int n;
string s[50];

int t[50][26];
int ans[26];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> s[i];

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < s[i].size(); ++j){
			t[i][s[i][j]-'a']++;
		}
	}
	
	for(int j = 0; j < 26; ++j){
		int res = 100000000;
		for(int i = 0; i < n; ++i){
			res = min(res, t[i][j]);
		}
		ans[j] = res;
	}
	
	for(int i = 0; i < 26; ++i){
		for(int j = 0; j < ans[i]; ++j) cout << (char)('a'+i);
	}
	cout << endl;
}