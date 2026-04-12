#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<sstream>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define per(i,n,x) for(int i=n;i>=x;i--)
#define sz(a) int(a.size())
#define rson mid+1,r,p<<1|1
#define pii pair<int,int>
#define lson l,mid,p<<1
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
using namespace std;
const double eps=1e-8;
const int mod=998244353;
const int N=1e5+10;
const int inf=1e9;
ll f[3030][3030][3];
int n,s,a[3030];
int main(){
	//ios::sync_with_stdio(false);
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&s);
	rep(i,1,n) scanf("%d",&a[i]);
	f[0][0][0]=1;
	rep(i,0,n-1) rep(j,0,s){
		(f[i+1][j][0]+=f[i][j][0])%=mod;
		(f[i+1][j][1]+=f[i][j][0]+f[i][j][1])%=mod;
		(f[i+1][j][2]+=f[i][j][0]+f[i][j][1]+f[i][j][2])%=mod;
		if(j+a[i+1]<=s){
			(f[i+1][j+a[i+1]][1]+=f[i][j][0]+f[i][j][1])%=mod;
			(f[i+1][j+a[i+1]][2]+=f[i][j][0]+f[i][j][1])%=mod;
		}
	}
	cout<<f[n][s][2]<<endl;
	return 0;
}
