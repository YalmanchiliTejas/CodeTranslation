#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using R = double;

int n;
string s[55];

int main(){
	cin >> n;
	for(int i=0; i < n; i++) cin >> s[i];
		string ans = "";
	for(char c = 'a';c<='z';c++){
		int mini = 100;
		for(int i = 0;i<n;i++){
			int cnt = 0;
			for(int j=0;j<s[i].size();j++){
				if(s[i][j] == c) cnt++;
			}
		mini = min(mini,cnt);
		}
		for(int i = 0;i<mini;i++){
			ans += c;
		}
	}
	cout << ans << endl;
}
