#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;

string make(string a, string b){
	string dp[60][60] = {};
	int a_len = a.size();
	int b_len = b.size();
	a = ' ' + a;
	b = ' ' + b;

	FOR(i,1,a_len+1){
		FOR(j,1,b_len+1){
			if(a[i]==b[j]) {
				dp[i][j] = dp[i-1][j-1] + a[i];
			}
			else {
				if (dp[i-1][j].size()>=dp[i][j-1].size()){
					dp[i][j] = dp[i-1][j];
				}
				else {
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}

		return dp[a_len][b_len];
}

int main(){
	int n;
	cin >> n;
	string str;
	vector<string> s;
	rep(i,n){
		cin >> str;
		sort(str.begin(),str.end());
		s.push_back(str);
	}

	string ans = s[0];

	FOR(i,1,n){
		ans = make(ans,s[i]);
	}

	cout << ans << "\n";

	return 0;
}



