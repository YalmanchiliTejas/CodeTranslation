#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const double inf=1e8;
int main(){
	int n,m;
	cin>>n>>m;
	vvi in(n,vi(m));
	rep(i,n)rep(j,m)cin>>in[i][j];
	if(n<=2||m<=2){
		int out=0;
		rep(i,n)rep(j,m)out+=in[i][j];
		cout<<out<<endl;
		return 0;
	}
	vi dp(40010);
	dp[200]=in[0][0]+in[1][0]+in[0][1]+in[n-1][m-1];
	loop(i,2,n+m-2){
		vi tmp(40010);
		rep(j,40010)if(dp[j]){
			int l=j%200,r=j/200;
			//l=0 r=1
			rep(q1,2)rep(q2,2){
				int L=l+q1,R=r+q2;
				if(i-L==n||L==R||R==m)continue;
				tmp[L+200*R]=max(tmp[L+200*R],dp[j]+in[i-L][L]+in[i-R][R]);
			}
		}
		dp=tmp;
	}
	cout<<dp[(m-2)+(m-1)*200]<<endl;
}







