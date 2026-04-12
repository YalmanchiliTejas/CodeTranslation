#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
const long long llinf=9223372036854775807ll;
const int N=100005;
long long lay[55],pat[55],used,x,ans,n,le;
void go(long long l)
{
	if(le==0)
	{
		cout<<ans;
		exit(0);
	}
	if(le>=lay[l])
		le-=lay[l],ans+=pat[l];
	else
	{
		le--;
		if(le==0)
		{
			cout<<ans;
			exit(0);
		}
		go(l-1);
		if(le==0)
		{
			cout<<ans;
			exit(0);
		}
		le--,ans++;
		if(le==0)
		{
			cout<<ans;
			exit(0);
		}
		go(l-1);
		if(le==0)
		{
			cout<<ans;
			exit(0);
		}
		le--;
		if(le==0)
		{
			cout<<ans;
			exit(0);
		}	
	}
}
int main(){
	cin>>n>>x;
	lay[0]=pat[0]=1;
	for(int i=1;i<=n;i++)
		lay[i]=lay[i-1]*2ll+3ll,pat[i]=pat[i-1]*2ll+1ll;
	le=x;
	go(n);
	cout<<ans;
	return 0;
}