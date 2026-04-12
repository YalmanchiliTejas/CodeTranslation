#include<functional>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<string>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// 上 左 下 右
const int N=100005,M=1000005,K=200005,mod=1000000007;
const long long llinf=9223372036854775807ll;
//int & long long
string s;
int k;
long long ans;
long long dfs(int now,int not0,bool free)
{
	long long ret=0;
	if(not0==k)
	{
		ret=1;
		return ret;
	}
	if(now==s.size()&&not0<k)
		return ret;
	if(!free)
	{
		if(s[now]=='0')
			ret=dfs(now+1,not0,false);
		else
		{
			for(int i=0;i<=int(s[now]-'0');i++)
			{
				if(i==0)
					ret+=dfs(now+1,not0,true);
				else if(i==int(s[now]-'0'))
					ret+=dfs(now+1,not0+1,false);
				else
					ret+=dfs(now+1,not0+1,true);
			}
		}
		return ret;
	}
	else
	{
		ret+=dfs(now+1,not0,true);
		ret+=dfs(now+1,not0+1,true)*9;
		return ret;
	}
}
int main(){
	cin>>s>>k;
	if(s.size()<k)
	{
		cout<<0;
		return 0;
	}
	ans=dfs(0,0,false);
	cout<<ans;
	return 0;
}