#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(){
	int n;
	cin >> n;
	vector<map<char,int>> mp(n);
	rep(i,n){
		string s;
		cin >> s;
		rep(j,s.size()){
			mp[i][s[j]]++;
		}
	}
	
	string ans;
	
	rep(j,26){
		int count = mp[0][alphabet[j]];
		rep(i,n){
			count = min(count, mp[i][alphabet[j]]);
		}
		if(count > 0){
			rep(i,count){
				ans += alphabet[j];
			}
		}
	}
	
	cout << ans << endl;
    return 0;
}

