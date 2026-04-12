#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+5;
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
int dp[120][120];
int a[120];	
int k;
int dfs(int pos,int sta,int lead,int limit){
	if(pos == -1) return sta == k;
	if(!lead&&!limit&&dp[pos][sta]!=-1) return dp[pos][sta];
	int up = limit?a[pos]:9;
	int tmp = 0;
	for(int i = 0;i <= up;++i){
		if(lead&&i == 0) tmp += dfs(pos - 1,sta,lead,limit&&i == a[pos]);
		else tmp += dfs(pos-1,sta + (i == 0?0:1),0,limit&&i == a[pos]);
	}
	if(!limit&&!lead) dp[pos][sta] = tmp;
	return tmp;
}
int main(){
	string s;
	cin >> s>>k;
	int l = s.size();
	int pos = 0;
	memset(dp,-1,sizeof dp);
	for(int i = l-1;i >= 0;-- i){
		a[pos++] = s[i] - '0';
	}
	cout <<	dfs(pos-1,0,1,1);
}
