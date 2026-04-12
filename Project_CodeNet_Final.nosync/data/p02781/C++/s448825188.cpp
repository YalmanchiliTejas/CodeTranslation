#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define mem0(s) memset(s,0,sizeof(s))
#define meminf(s) memset(s,0x3f,sizeof(s))
#define mp_insert(a,b,c) mp.insert(map<pair<int,int>,int>::value_type(make_pair(a,b),c))
double pi=acos(-1);
typedef long long ll;
const double ex=1e-5;
typedef unsigned long long ull;
inline ll lowbit(ll x){return x&(-x);}
inline ll min(ll a,ll b){return a<b?a:b;}
inline ll max(ll a,ll b){return a>b?a:b;}
const int INF=0x3f3f3f3f,max_n=200005;
const int mod=1000000007;
inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
char s[1005];
int n,k;
int dp[105][4][2];
int dfs(int pos,int cnt,int limit)
{
	if(pos==n+1)return cnt==k;//如果恰为k位，回溯1，累加到前面，否则忽视这个情况
	if(cnt>k)return 0;//cnt不是k忽视这个情况
	if(dp[pos][cnt][limit]!=-1)//已经访问过啦
	{
		return dp[pos][cnt][limit];
	}
	int high=limit?s[pos]-'0':9;
	int sum=0;
	for(int i=0;i<=high;i++)
	{
		sum+=dfs(pos+1,cnt+(i!=0),limit&&i==high);//向下一层搜索
	}
	return dp[pos][cnt][limit]=sum;//返回时要记忆化!
	
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>s+1;
	cin>>k;
	n=strlen(s+1);
	cout<<dfs(1,0,1);//保证
}