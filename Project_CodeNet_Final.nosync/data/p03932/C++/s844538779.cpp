#define _USE_MATH_DEFINES
#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
#pragma endregion //#include
/////////

#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9+7;
const LL LINF = (LL)4e18+20;
const LD PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;

/*
thx
http://kmjp.hatenablog.jp/entry/2016/11/25/0930
2点を同時に動かす
動き方は{RR,RD,DR,DD}の4通り
同じ地点に到達するのはスタート地点と
移動後に同じ場所になるかだけ、
以前の位置には到達できない(RかDの移動だけなので)
*マンハッタン距離として増加方向だけ許されている
*/
void solve(){
	int H,W;
	cin>>H>>W;
	vector<vector<int> > A(H,vector<int>(W));
	for(int h=0;h<H;++h){
		for(int w=0;w<W;++w){
			cin>>A[h][w];
		}
	}

	vector<vector<vector<LL> > > dp(H+W,
		vector<vector<LL> >(H,
			vector<LL>(W,0)
			)
			);
	dp[0][0][0] = A[0][0];
	for(int i=0;i<H+W-2;++i){//
		int x1,x2,y1,y2;
		//位置を順番に総当り
		for(y1=0;y1<H;++y1){
		for(y2=0;y2<H;++y2){
			x1 = i-y1;
			x2 = i-y2;
			//範囲外,y1は範囲内ループさせてる
			if(x1<0 || x1>=W || x2<0 || x2>=W)continue;
			LL v = dp[i][y1][y2];
			//RR
			if(x1+1<W && x2+1<W ){
				if(y1==y2){//同じ位置なので増えるの移動先はひとつ
					dp[i+1][y1][y2] = max(dp[i+1][y1][y2],v+A[y1][x1+1]);
				}else{
					dp[i+1][y1][y2] = max(dp[i+1][y1][y2],v+A[y1][x1+1]+A[y2][x2+1]);
				}
			}
			//RD
			if(x1+1<W && y2+1<H){
				if(x1+1==x2){
					dp[i+1][y1][y2+1]=max(dp[i+1][y1][y2+1],v+A[y1][x1+1]);
				}else{
					dp[i+1][y1][y2+1]=max(dp[i+1][y1][y2+1],v+A[y1][x1+1]+A[y2+1][x2]);
				}
			}
			//DR
			if(y1+1<H && x2+1<W){
				if(y1+1==y2){
					dp[i+1][y1+1][y2]=max(dp[i+1][y1+1][y2],v+A[y1+1][x1]);
				}else{
					dp[i+1][y1+1][y2]=max(dp[i+1][y1+1][y2],v+A[y1+1][x1]+A[y2][x2+1]);
				}
			}
			//DD
			if(y1+1<H && y2+1<H){
				if(y1==y2){//y1+1==y2+1
					dp[i+1][y1+1][y2+1]=max(dp[i+1][y1+1][y2+1],v+A[y1+1][x1]);
				}else{
					dp[i+1][y1+1][y2+1]=max(dp[i+1][y1+1][y2+1],v+A[y1+1][x1]+A[y2+1][x2]);
				}
			}
		}}
	}
	LL ans = dp[H+W-1-1][H-1][H-1];
	cout << ans << endl;
}

#pragma region main
signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()
