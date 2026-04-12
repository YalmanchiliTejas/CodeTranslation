//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n); if(!n) return 0;
		vector<P>state(0);
		for(int i=1;i<=n;i++)
		{
			int t; scanf("%d",&t);
			if(i%2==1)
			{
				if(state.empty() || state[state.size()-1].second!=t)
				{
					state.pb(mp(1,t));
				}
				else
				{
					state[state.size()-1].first++;
				}
			}
			else
			{
				if(state[state.size()-1].second==t)
				{
					state[state.size()-1].first++;
				}
				else
				{
					int v=state[state.size()-1].first;
					state.pop_back();
					if(!state.empty()) state[state.size()-1].first+=(v+1);
					else state.pb(mp(v+1,t));
				}
			}
		}
		int ret=0;
		for(int i=0;i<state.size();i++) if(!state[i].second) ret+=state[i].first;
		printf("%d\n",ret);
	}
}