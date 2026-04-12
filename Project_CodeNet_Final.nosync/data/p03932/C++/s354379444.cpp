#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
using llong = long long;
using vi    = vector<int>;
using vvi   = vector<vi >;
using vvvi  = vector<vvi >;
using pii   = pair<int,int>;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

using vl    = vector<long long>;
using vvl   = vector<vl >;
using vvvl  = vector<vvl >;

const int dy[]={-1,0};
const int dx[]={0,-1};

template<class T,class U> inline bool chmax(T &a,const U &b){if(a<b){a=b;return true;}return false;}
template<class T,class U> inline bool chmin(T &a,const U &b){if(a>b){a=b;return true;}return false;}

int main(){//Refering other editorials.
	int h,w;
	cin>>h>>w;
	
	vvl a(h,vl(w));
	REP(i,h)REP(j,w) cin>>a[i][j];
	
	vvvl dp(h,vvl(h,vl(h+w-1,0LL)));//dp[ey][sy][ey+ex]:=(Eがeyに,Sがsyに,EとSの移動量がey+exのときのお土産個数).
	dp[0][0][0]=a[0][0];
	auto jud=[=](const int y,const int x)->bool{
		return (0<=y and y<h and 0<=x and x<w);
	};
	REP(i,h)REP(j,h)REP(k,h+w-1){
		int ey=i, ex=k-i, sy=j, sx=k-j;
		if(jud(ey,ex) and jud(sy,sx)){
			REP(ii,2)REP(jj,2){
				int ney=ey+dy[ii], nex=ex+dx[ii], nsy=sy+dy[jj], nsx=sx+dx[jj];
				if(jud(ney,nex) and jud(nsy,nsx)){
					if(ey==sy and ex==sx) chmax(dp[i][j][k],dp[ney][nsy][k-1]+a[ey][ex]);
					else chmax(dp[i][j][k],dp[ney][nsy][k-1]+a[ey][ex]+a[sy][sx]);
				}
			}
		}
	}
	
	cout<<dp[h-1][h-1][h+w-2]<<endl;
}