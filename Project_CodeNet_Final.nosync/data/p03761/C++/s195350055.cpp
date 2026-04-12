#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
	int n;
	cin>>n;
	vector<string> ss(n);
	rep(i,n)cin>>ss[i];
	vector<vector<int>> char_cnt(n, vector<int>(30,0));
	rep(i,n){
		string t = ss[i];
		rep(j,t.size()){
			char_cnt[i][t[j]-'a']++;
		}
	}
	vector<pair<char,int>> ans;
	rep(j,'z'-'a'+1){
		int cnt = inf;
		rep(i,n){
			cnt = min(cnt, char_cnt[i][j]);
		}
		if(cnt>0)ans.push_back(make_pair('a'+j,cnt));
	}
	for(auto x : ans){
		rep(i,x.second){
			cout<<x.first;
		}
	}
	cout<<endl;
	return 0;
}