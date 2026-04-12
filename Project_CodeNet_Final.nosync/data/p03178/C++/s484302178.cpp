#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
ll dp[10001][100][2]={};//dp[i][j][k]:i桁目まで読んだ、j:modD k:K以下である可能性がある
int main(){
	ll MOD=1e+9+7;
	string K;
	scan(K);
	reverse(K.begin(),K.end()); //後ろの桁から見ていく
	int D;
	scan(D);
	int N=K.size();
	dp[0][0][1]=1;
	rep(i,N){
		rep(j,D){
			rep(k,2){
				rep(d,10){
					bool leq=d<(K[i]-'0')||(k==1&&d==(K[i]-'0'));
					dp[i+1][(j+d)%D][leq]+=dp[i][j][k];
					dp[i+1][(j+d)%D][leq]%=MOD;
				}
			}
		}
	}
	prin((dp[N][0][1]-1+MOD)%MOD);//0を除く
	return 0;
}
