#include<bits/stdc++.h>

using namespace std;
#define pb push_back
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef set<char> setc;
typedef set<int> seti;
map<char,int> mp;
void solve(){
	//write solution here
	int n;
	cin>>n;
	map<char,int> mp[n];
	map<char,int> maxim;
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		for(int j = 0; j < s.length(); j++){
			mp[i][s[j]] += 1;
		}
	}
	vi counts(26);
	for(int i = 0; i < 26; i++){
		int minim = 10000;
		char ch = 'a'+i;
		for(int j = 0; j < n; j++){
			int p = mp[j]['a'+i];
			if(minim>p) minim = p;
		}
		for(int i = 0; i < minim; i++){
			cout<<ch;
		}
	}
	cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}