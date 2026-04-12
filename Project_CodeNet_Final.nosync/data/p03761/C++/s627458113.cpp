#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<vector<int>> a(n,vector<int>(26));
	rep(i,n){
		string s;cin >> s;
		rep(j,s.size()){
			a.at(i).at(s.at(j)-'a')++;
		}
	}
	string ans="";
	rep(i,26){
		int cnt=100;
		rep(j,n){
			cnt=min(cnt,a.at(j).at(i));
		}
		char c='a'+i;
		rep(j,cnt){
			ans+=c;
		}
	}
	cout << ans << endl;
}
