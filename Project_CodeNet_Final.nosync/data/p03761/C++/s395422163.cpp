#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<vector<lli>> a(n, vector<lli>(26));
	rep(i, n){
		string s;
		cin >> s;
		rep(j, s.size()){
			a[i][s[j]-'a']++;
		}
	}
	string ans = "";
	rep(i, 26){
		lli minv = 1e9;
		rep(j, n){
			minv = min(minv, a[j][i]);
		}
		rep(j, minv) ans+=('a'+i);
	}
	cout << ans << endl;
	return 0;
}
