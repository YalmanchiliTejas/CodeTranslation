#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

bool flg[100005][27];
vector<int> G[100005];
	
int V,E;
char A[100005]={0};

int main()
{
	scanf("%d%d\n",&V,&E);
	for(int i=0;i<V;i++)
	{
		scanf("%c%*c",&A[i]);
	}
	for(int i=0;i<E;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		G[s].push_back(t);
		G[t].push_back(s);
	}
	for(int i=0;i<V;i++)
	{
		if(A[i]!='?')flg[i][A[i]-'a']=1;
	}
	for(int i=0;i<V;i++)
	{
		if(A[i]=='?')
		{
			for(char x='a';x<='z';x++)
			{
				int j;
				for(j=0;j<G[i].size();j++)
				{
					if(flg[G[i][j]][x-'a'])break;
				}
				if(j==G[i].size())
				{
					A[i]=x;
					flg[i][x-'a']=1;
					break;
				}
			}
		}
	}
	puts(A);
}
