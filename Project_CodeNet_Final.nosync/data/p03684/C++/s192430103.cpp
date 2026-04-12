#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
int par[200005];
int fin(int x)
{
	if (par[x]==-1)return x; else return par[x]=fin(par[x]);
}
void bing(int x,int y)
{
	par[fin(x)]=fin(y);
}
pair<int,pair<int,int> > a[100005];
pair<int,pair<int,int> >mi[200005];
bool com(pair<int,pair<int,int> >x,pair<int,pair<int,int> >y)
{
	return x.second.first<y.second.first;
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(par,-1,sizeof(par)); 
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].first,&a[i].second.first);
		a[i].second.second=i;
	}
	sort(a,a+n);
	int cnt=0;
	for(int i=1;i<n;i++)
	{
//		cout<<a[i].first<<" ";
		mi[cnt].first=a[i].first-a[i-1].first;
		mi[cnt].second.first=a[i].second.second;
		mi[cnt++].second.second=a[i-1].second.second;
//		cout<<mi[cnt-1].first<<endl;
	}
	sort(a,a+n,com);
	for(int i=1;i<n;i++)
	{
	//	cout<<mi[cnt].first<<endl;
		mi[cnt].first=a[i].second.first-a[i-1].second.first;
		mi[cnt].second.first=a[i].second.second;
		mi[cnt++].second.second=a[i-1].second.second;
//		cout<<mi[cnt-1].first<<endl;
	}
	
	sort(mi,mi+cnt);
	long long res=0;
	for(int i=0;i<cnt;i++)
	{
		int x=mi[i].second.first;
		int y=mi[i].second.second;
		if(fin(x)!=fin(y))
		{
			bing(x,y);
			res+=mi[i].first;
		}
	}
	cout<<res;
	return 0;
}