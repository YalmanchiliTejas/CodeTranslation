//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//これは、頭が悪く競プロが世界で一番できないHIR180が
//IOI2014日本代表になるまでのN日間の記録である。
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int num[100005];
//0..w 1...h
int main()
{
	srand((unsigned int)time(NULL));
	while(1)
	{
		vector<int>vec[2];
		int n; scanf("%d",&n); if(!n) return 0;
		num[0]=-1;
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);
		for(int i=1;i<=n;i++)
		{
			if(i%2==1)
			{
				if(num[i-1]!=num[i])
				{
					vec[num[i]].pb(i);
				}
				else
				{
					if(vec[num[i]].empty()) vec[num[i]].pb(i);
					else vec[num[i]][vec[num[i]].size()-1]=i;
				}
			}
			else
			{
				if(num[i-1]==num[i])
				{
					if(vec[num[i]].empty()) vec[num[i]].pb(i);
					else vec[num[i]][vec[num[i]].size()-1]=i;
				}
				else
				{
					vec[1-num[i]].pop_back();
					if(vec[num[i]].empty()) vec[num[i]].pb(i);
					else vec[num[i]][vec[num[i]].size()-1]=i;
				}
			}
		}
		int ret=0;
		if(vec[0].empty()) ret=0; else if(vec[1].empty()) ret=n;else{
		if(vec[0][0]>vec[1][0])
		{
			for(int j=0;j<vec[0].size();j++) ret+=vec[0][j]-vec[1][j];
		}
		else
		{
			ret+=vec[0][0];
			for(int j=1;j<vec[0].size();j++) ret+=vec[0][j]-vec[1][j-1];
		}}
		printf("%d\n",ret);
	}
}