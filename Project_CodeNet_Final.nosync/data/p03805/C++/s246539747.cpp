//Author : pakhandi
//
using namespace std;

#include <bits/stdc++.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)

#define si(n) scanf("%d", &n)
#define sll(l) scanf("%lld",&l)

#define debug(x) cout<<"\n#("<<x<<")#\n"
#define nline printf("\n")

#define mem(a,i) memset(a,i,sizeof(a))

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

#define PB push_back
#define SZ size
#define MP make_pair

#define IGNORE cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

const ll INF = (1LL << 58);
const bool DEBUG = 0;

int nodes, edges;
std::vector<pair<int, int> > edge;
std::vector<int> v;

int main()
{
	int i, j;

	si(nodes);	si(edges);

	fl(i,0,edges)
	{
		int x, y;
		si(x);	si(y);
		edge.PB(MP(x, y));
	}

	fl(i,1,nodes)
	{
		v.PB(i + 1);
	}

	int ans = 0;

	do
	{
		int prev = 1;
		bool got = 1;
		// cout << " --- \n";
		fl(j,0,nodes - 1)
		{
			int next = v[j];
			// cout << prev << " " << next << "\n";
			bool thisGot = 0;
			fl(i,0,edges)
			{
				if(edge[i].first == prev && edge[i].second == next)
					thisGot = 1;
				if(edge[i].second == prev && edge[i].first == next)
					thisGot = 1;
			}
			if(!thisGot)
			{
				got = 0;
				break;
			}
			prev = next;
		}
		if(got)
			ans++;

	}while(next_permutation(v.begin(), v.end()));

	printf("%d\n", ans);


	return 0;
}
/*
	Powered by Buggy Plugin
*/
