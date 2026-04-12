#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

int H,W;
int dp [400] [200] [200];
const int INF = 1e9;

bool in_range(int x,int y){
	return x >= 0 && x < W && y >= 0 && y < H;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> H >> W;
	vector< vector<int> > A(H,vector<int>(W));
	FOR(i,0,H) FOR(j,0,W){
		cin >> A [i] [j];
	}

	fill(dp [0] [0],dp [H + W] [0],-INF);
	dp [0] [0] [0] = A [0] [0];
	FOR(i,0,H + W - 1) FOR(j,0,W) FOR(k,0,W) if(dp [i] [j] [k] >= 0){
		FOR(l,0,4){
			int x1 = j + l / 2,y1 = i - x1 + 1,x2 = k + l % 2,y2 = i - x2 + 1;
			if(in_range(x1,y1) == false || in_range(x2,y2) == false) continue;
			int add;
			if(x1 == x2 && y1 == y2){
				add = A [y1] [x1];
			}
			else{
				add = A [y1] [x1] + A [y2] [x2];
			}
			chmax(dp [i + 1] [x1] [x2],dp [i] [j] [k] + add);
		}
	}

	cout << dp [H + W - 2] [W - 1] [W - 1] << endl;

	return 0;
}
