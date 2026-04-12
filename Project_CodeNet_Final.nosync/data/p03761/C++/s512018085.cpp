#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main(){
	int n;
	cin >> n;
	vector<string> input(n);
	rep(i,n) cin >> input[i];
	int table[n][26];
	rep(i,n){
		rep(j,26){
			table[i][j]=0;
		}
	}
	rep(i,n){
		rep(j,input[i].size()){
			// cout << input[i][j]-97 << endl;
			table[i][input[i][j]-97]++;
		}
	}
	string ans = "";
	rep(i,26){
		int nin = INF;
		rep(j,n){
			nin = min(nin,table[j][i]);
		}
		rep(j,nin)
			ans+=char(i+97);
	}
	cout << ans << endl;
	return 0;
}