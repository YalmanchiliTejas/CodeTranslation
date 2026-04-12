/*
 KMnO4 is _____________ agent.
*/
#include <set>          
#include <map>           
#include <list>
#include <ctime>
#include <deque>         
#include <bitset>        
#include <vector>
#include <list>
#include <stack>
#include <random>		 
#include <string>       
#include <numeric>      //  needed for  accumulate
#include <utility>      // needed for std:: move
#include <iterator> 
#include <iostream>   
#include <algorithm> 
#include <functional>    
#include <cmath>         
#pragma warning(disable:4996) // ignore this
#define siz size()
#define ve vector
#define pb push_back
#define mp make_pair                     
#define rsz(n) resize(n)
#define get_int(x) scanf("%d",&x)              
#define get_long(x) scanf("%lld",&x)           
#define srt(x) sort(x.begin(),x.end())         
#define gor(i,x,y) for(int i=x;i<y;i++)        
#define mod static_cast<long long> (1e9+7)     
#define sumx(x) accumulate(x.begin(),x.end(),0LL)
#define ti(v) for(int i=0,u,w;i<v.size()-1;i++,v[u-1].pb(w-1),v[w-1].pb(u-1))scanf("%d%d",&u,&w) ; // rarely used 
#define FU 2e9
#define SZ 15000000
#define testing 1
#include <queue>
using namespace std;
template<typename T>									
istream& operator >> (istream& in, ve<T> &v)
{
	for (auto &x : v)
		in >> x;
	return in;
}
template<typename T>									
ostream& operator<<(ostream& in, ve<T> &v)
{
	for (auto &x : v)
		in << x << " ";
	return in;
}
long long fast(long long a,long long b)
{
	if(b==0)
		return 1;
	long long ans=a;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
}
class DISJ
{
	/*
	Super Linear time:O(n.a(n)) ( amortized )
	[ rank union + path compression ]
	*/
	vector<int> rank, parent;
	int SIZE;
public:
	DISJ(int N) :SIZE(N), rank(N, 0), parent(N)
	{
		for (int i = 0; i<N; i++)
			parent[i] = i, rank[i] = 0;
	}
	int find_set(int x)
	{
		if (parent[x] == x)    // root node check
			return x;
		parent[x] = find_set(parent[x]); // path compression
		return parent[x];
	}
	void link(int x, int y)
	{
		if (rank[x] == rank[y])
		{
			rank[x]++;
			parent[y] = x;
			return;
		}
		if (rank[x]<rank[y])
			parent[x] = y;
		else
			parent[y] = x;
	}
	void unite(int x, int y)
	{
		x = find_set(x);
		y = find_set(y);
		if (x != y)
			link(x, y);
	}
	bool same_set(int x, int y)
	{
		return (find_set(x) == find_set(y));
	}
	/* Reference : CLRS 3rd edition 21st chapter Data Structure for Disjoint sets */
};
class solve
{
	long long int n,m;
	map<pair<int,int>,int > S2,S1;
public:
	solve()
	{
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin >> x >> y;
			S1.insert(make_pair(make_pair(x,y),i));
		}
		int c_x=0,c_y=0;
		vector<pair<int,int> > v1,v2;
		int a=0;
		for(auto &x:S1)
		{
			v1.push_back(make_pair(x.first.first,a));
			v2.push_back(make_pair(x.first.second,a));
			++a;
		}
		srt(v2);
		multimap<int,pair<int,int> > My,Mx;
		n=v1.size();
		for(int i=1;i<n;i++)
		{
			Mx.insert(make_pair(v1[i].first-v1[i-1].first,make_pair(v1[i].second,v1[i-1].second)));
			My.insert(make_pair(v2[i].first-v2[i-1].first,make_pair(v2[i].second,v2[i-1].second)));
		}
		DISJ D(n);
		int ans=0;
		while(!Mx.empty()&& !My.empty())
		{
			int p1=Mx.begin()->first;
			int p2=My.begin()->first;
			if(p1<=p2)
			{
				int u=Mx.begin()->second.first;
				int v=Mx.begin()->second.second;
				if(D.find_set(u)!=D.find_set(v))
				{
					ans+=p1;
				}
				D.unite(u,v);
				Mx.erase(Mx.begin());
			}
			else
			{
				int u=My.begin()->second.first;
				int v=My.begin()->second.second;
				if(D.find_set(u)!=D.find_set(v))
				{
					ans+=p2;
				}
				D.unite(u,v);
				My.erase(My.begin());
			}
		}
		cout << ans <<endl;
	}
};
int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--)
		new solve;
	return 0;
}