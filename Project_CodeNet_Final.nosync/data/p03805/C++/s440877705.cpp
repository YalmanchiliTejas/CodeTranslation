#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<complex>
#include<string>
#include<cstring>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
#define INF 100000000
#define debug(x) cout<<#x<<": "<<x<<endl

#define all(x) x.begin(),x.end()
typedef pair<int,int> P;
typedef pair<int,P> PP;
int n,m;
int co;
int link[9][9];
int ar[10];
int used[10];
void saiki(int nn)
{
	if(nn==n)
	{
		int ff=1;
		rep(i,n-1)
		{
			if(link[ar[i]][ar[i+1]]==0)break;
			if(i==n-2)co++;
		}
		return;
	}
	if(nn==0)
	{
		ar[nn]=0;
		used[0]=1;
		saiki(nn+1);
	}
	else
	{
		rep(i,n)
		{
			if(used[i])continue;
			ar[nn]=i;
			used[i]=1;
			saiki(nn+1);
			used[i]=0;
		}
	}
	return;
}
int main()
{
	int a,b;
	cin>>n>>m;
	rep(i,m)
	{
		cin>>a>>b;
		a--;b--;
		link[a][b]=1;
		link[b][a]=1;
	}
	saiki(0);
	cout<<co<<endl;
	return 0;
}