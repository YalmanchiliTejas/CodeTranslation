#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<char, int> mp;
	string s;
	cin >> s;
	rep(i,s.size()){
		++mp[s[i]];
	}
	rep(i,n-1){
		map<char, int> mp2;
		cin >> s;
		rep(i,s.size()){
			++mp2[s[i]];
		}
		for(auto p : mp){
			chmin(mp[p.first], mp2[p.first]);
		}
	}
	string ans = "";
	for(auto p : mp){
		rep(i,p.second) ans += p.first;
	}
	cout << ans << endl;
	return 0;
}