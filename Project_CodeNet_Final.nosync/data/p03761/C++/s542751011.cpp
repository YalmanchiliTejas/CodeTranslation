#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	vector<vector<int>> a(n,vector<int>(26,0));
	rep(i,n){
		rep(j,s[i].size()){
			a[i][s[i][j]-'a']++;
		}
	}
	vector<int> m(26,10000);
	rep(i,26){
		rep(j,n){
			m[i]=min(m[i],a[j][i]);
		}
	}
	rep(i,26){
		char c='a'+i;
		rep(j,m[i]){
			cout << c;
		}
	}
	cout << endl;
}