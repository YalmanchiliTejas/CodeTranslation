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

class graph
{
	vector<vector<int> > adjList;
	int nodes;

	public:
		graph(int n)
		{
			nodes = n;
			adjList.resize(n+1);
		}

		void addEdge(int u, int v)
		{
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}

		ll get()
		{
		    int ans = 0;
		    int count = 1;
			vector<bool> v(nodes+1 , false);
			find(-1 , 1 , v , ans , count);
			
			return ans;
		}

		void find(int parent , int current , vector<bool>& v , int& ans , int count)
		{
			v[current] = true;
            if(count == nodes)
                ans++;
			for(auto n : adjList[current])
			{
				if(n != parent && v[n] == false)
				{
					find(current , n , v , ans , count+1);
				}
			}
			v[current] = false;
		}
};

int main()
{
	FAST;
	int n,edge;
	cin >> n >> edge;
	graph g(n);
	while(edge--)
	{
		int u,v;
		cin >> u >> v;
		g.addEdge(u , v);
	}

	cout << g.get();
	return 0;
}