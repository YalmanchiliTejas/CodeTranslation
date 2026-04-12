#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define pip pair<int,pair<int,int> >
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int n;
pair<int,pii> a[200005];
vector <pair<int,pii> >vec;
set <pair<int,pair<int,int> > > squ;
int f[200005];
priority_queue <pip,vector <pip>,greater<pip> >que;

int find(int x)
{
	return (x==f[x]?x:f[x]=find(f[x]));
}

int add(int x,int y)
{
	x=find(x);
	y=find(y);
	if(rand()&1) f[x]=y;else f[y]=x;
}

bool compare1(pair<int,pii> a,pair<int,pii> b)
{
	return a.second.first<b.second.first;
}

bool compare2(pair<int,pii> a,pair<int,pii> b)
{
	return a.second.second<b.second.second;
}

void init()
{
	for(int i=0;i<200005;i++)
	{
		f[i]=i;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].second.first,&a[i].second.second);
		a[i].first=i;
	}
	sort(a,a+n,compare1);
	for(int i=0;i<n-1;i++)
	{
		vec.push_back(mp(min(abs(a[i+1].second.first-a[i].second.first),abs(a[i+1].second.second-a[i].second.second)),mp(a[i].first,a[i+1].first)));
	}
	sort(a,a+n,compare2);
	for(int i=0;i<n-1;i++)
	{
		vec.push_back(mp(min(abs(a[i+1].second.first-a[i].second.first),abs(a[i+1].second.second-a[i].second.second)),mp(a[i].first,a[i+1].first)));
	}
	for(int i=0;i<vec.size();i++)
	{
		que.push(vec[i]);
//		squ.insert(vec[i]);
	}
//	for(set <pair<int,pii> > ::iterator it=squ.begin();it!=squ.end();it++)
//	{
//		cout<<it->first<<' '<<it->second.first<<' '<<it->second.second<<endl;
//	}
//	cout<<que.size()<<endl;
	init();
	int k=0;
	ll ans=0;
	while(1)
	{
//		cout<<que.size()<<endl;
//		system("pause");
		if(k==n-1) break;
		pip t=que.top();
		que.pop();
		if(find(t.second.first)==find(t.second.second)) continue;
		k++;
//		cout<<k<<endl;
		ans+=t.first;
		add(t.second.first,t.second.second);
	}
	cout<<ans<<Endl;
	return 0;
}