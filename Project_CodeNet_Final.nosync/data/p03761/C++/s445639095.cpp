#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,-1,0,1},dy={1,0,-1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s.at(i);
	vector<vector<int>> cnt(n,vector<int>(26));
	rep(i,n){
		rep(j,s.at(i).size()){
			cnt.at(i).at(s.at(i).at(j) - 'a')++;
		}
	}
	rep(i,26){
		int num = 100000;
		rep(j,n){
			num = min(num, cnt.at(j).at(i));
		}
		rep(j,num){
			char c = i + 'a';
			cout << c;
		}
	}
	cout << endl;
}