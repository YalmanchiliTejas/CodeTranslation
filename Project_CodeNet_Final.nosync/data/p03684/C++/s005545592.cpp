#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm> 
#include <ctime>

#define MaxN 100005
#define INF 2140000000
#define MOD 1000000007
using namespace std;

int N,Ans=0,P1=1,P2=1,K=1,father[MaxN];
pair<int,int>Xaxis[MaxN],Yaxis[MaxN];
vector<pair<pair<int,int>,int> >T;
bool cond(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b)
{
	return a.second<b.second;
}
int find(int x)
{
	int y=x,aux;
	while(father[x]!=x)
		x=father[x];
	while(x!=y)
	{
		aux=father[y];
		father[y]=x;
		y=aux;
	}
	return x;
}
void unite(int x,int y)
{
	x=find(x),y=find(y);
	father[x]=y;
}
int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>Xaxis[i].first>>Yaxis[i].first;
		Yaxis[i].second=Xaxis[i].second=i;
		father[i]=i;
	}
	sort(Xaxis+1,Xaxis+1+N);
	sort(Yaxis+1,Yaxis+1+N);
	for(int i=1;i<N;i++)
	{
		int D=abs(Xaxis[i].first-Xaxis[i+1].first);
		T.push_back(make_pair(make_pair(Xaxis[i].second,Xaxis[i+1].second),D));
		D=abs(Yaxis[i].first-Yaxis[i+1].first);
		T.push_back(make_pair(make_pair(Yaxis[i].second,Yaxis[i+1].second),D));
	}
	sort(T.begin(),T.end(),cond);
	for(int i=0;i<T.size()&&K<N;i++)
	{
		if(find(T[i].first.first)!=find(T[i].first.second))
		{
			K++;
			unite(T[i].first.first,T[i].first.second);
			Ans+=T[i].second;
		}
	}
	cout<<Ans;
	return 0;
}