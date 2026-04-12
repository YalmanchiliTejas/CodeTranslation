#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;

vector<vector<int>> ab;
int countt;
vector<int> color;
int nn;

void dfs(int n)
{
	//cout<<n<<endl;
	color[n]=1;
	//rep(i,nn){if(i)cout<<" ";cout<<color[i];}cout<<endl;
	rep(i,ab[n].size())
	{
		if(color[ab[n][i]]==0)
		{
			dfs(ab[n][i]);
		}
	}

	bool foo=true;
	rep(i,color.size())
	{
		if(color[i]==0)foo=false;
	}
	if(foo)countt+=1;
	color[n] = 0;
	return ;
}


int main()
{
	int m;cin>>nn>>m;

	rep(i,nn)
	{
		ab.push_back(vector<int>());
	}
	rep(i,m)
	{
		int foo,fooo;cin >> foo >> fooo;
		ab[foo-1].push_back(fooo-1);
		ab[fooo-1].push_back(foo-1);
	}
	countt=0;
	rep(i,nn)color.push_back(0);

	dfs(0);
	cout << countt << endl;
	return 0;
}