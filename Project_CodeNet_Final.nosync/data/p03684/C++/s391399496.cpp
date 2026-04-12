// Dont hack this or I hack ur mama
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#define ll long long 
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
using namespace std;

////////////// END OF TEMPLATE

const int nmax = 100100;

int x[nmax],y[nmax];
int indices[nmax];
int r[nmax];
int N;
vector < pair < ll, pair < int ,int > > > edges;

int root(int index)
{
	return (r[index] == index) ? index : (r[index] = root(r[index]));
}
void read()
{
	cin >> N;
	for(int i =0 ; i < N; ++i)
	{
		cin >> x[i] >> y[i];
		indices[i] = i;
		r[i] = i;
	}
	sort(indices, indices + N, [](int a, int b){
				return x[a] < x[b];
			});
	for(int i = 0 ; i < N - 1; ++i)
	{
		edges.push_back(make_pair(x[indices[i+1]]-x[indices[i]], make_pair(indices[i+1],indices[i])));
	}
	sort(indices, indices + N, [](int a, int b){
				return y[a] < y[b];
			});
	for(int i = 0 ; i < N - 1; ++i)
	{
		edges.push_back(make_pair(y[indices[i+1]]-y[indices[i]], make_pair(indices[i+1],indices[i])));
	}
	sort(edges.begin(), edges.end());
	ll ans = 0;
	for(int i = 0 ; i < edges.size(); ++i)
	{
		if(root(r[edges[i].second.first]) == root(r[edges[i].second.second]))
			continue;
		ans+=edges[i].first;
		r[root(edges[i].second.first)]  = root(edges[i].second.second);	
	}	
	cout << ans << endl;
}
void solve()
{

}
int main()
{
	std::ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}
