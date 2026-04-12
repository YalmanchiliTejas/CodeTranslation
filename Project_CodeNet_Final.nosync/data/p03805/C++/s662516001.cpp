//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include <climits>
#include <cmath>
#include <cstring>

#include <iomanip>

using namespace std;

#define FAST       			ios_base :: sync_with_stdio(false); cin.tie(NULL); 
#define endl "\n"

typedef long long int  ll;
typedef unsigned long long int ull;

int g[9][9];

int main()
{
	FAST;
	
    memset(g , 0 , sizeof(g));
	int n,edge;
	cin >> n >> edge;
	while(edge--)
	{
		int u,v;
		cin >> u >> v;
		g[u-1][v-1] = g[v-1][u-1] = 1;
	}
	
	vector<int> a(n);
	for(int i=0 ; i<n ; i++)
	    a[i] = i;
	
	int ans = 0;
	do
	{
	    bool ok = true;
	    for(int i=0 ; i<n-1 ; i++)
	    {
	        if(!g[a[i]][a[i+1]])    ok = false;
	    }
	    if(ok)  ans++;
	}while(next_permutation(a.begin()+1 , a.end()) );

	cout << ans;
	return 0;
}