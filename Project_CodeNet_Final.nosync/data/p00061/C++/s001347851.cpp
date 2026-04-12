#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n,a;
	pair<int,int> teams[100];
	int rank[101];
	fill(rank,rank+101,0);
	int cnt=0;
	while(scanf("%d,%d",&n,&a),n)
	{
		teams[cnt].first=a; teams[cnt].second=n;
		cnt++;
	}

	sort(teams,teams+cnt);
	int r=0;
	for(int i = cnt-1; 0 <= i; --i)
	{
		if(i<cnt-1&&teams[i+1].first==teams[i].first)
		{
			rank[teams[i].second]=r;
		}
		else
		{
			++r;
			rank[teams[i].second]=r;
		}
	}
	while(cin>>n)
	{
		cout<<rank[n]<<endl;
	}
  return 0;
}