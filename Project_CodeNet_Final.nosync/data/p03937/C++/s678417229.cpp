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
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int d2x[2] = {0,1};
int d2y[2] = {1,0};

int main(){
	int H,W; cin>>H>>W;
	vector<vector<char>> nap(H+2,vector<char> (W+2,'.'));
	REP(i,H)REP(j,W)cin>>nap[i][j];
	queue<ip> Q;
	Q.push(make_pair(1, 1));
	nap[1][1] = '.';
	while(!Q.empty()){
		int x = Q.front().second, y = Q.front().first;
		Q.pop();
		rep(i,2){
			int dy = y + d2y[i], dx = x + d2x[i];
			if(nap[dy][dx] == '#'){
				Q.push(make_pair(dy, dx));
				nap[dy][dx] = '.';
				break;
			}
		}
	}
	REP(i,H)REP(j,W)if(nap[i][j] == '#'){cout<<"Impossible"<<endl; return 0;}
	cout<<"Possible"<<endl;
	return 0;
}