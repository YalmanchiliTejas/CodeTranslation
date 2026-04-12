#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define eps 1e-13
#define PI 3.141592653589793238L
#define INF 1000000011
#define INFLL 1000000000000000011LL
#define space printf(" ")
#define endl printf("\n")
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>
#define mp make_pair
#define F first
#define S second
#define pb(x) push_back(x)
#define fo(i,a,n) for(i = (a); i < (n); i++)
#define sd(x) scanf("%d", &(x))
#define pd(x) printf("%d", (x))
#define pdn(x) printf("%d\n", (x))
#define slld(x) scanf("%lld", &(x))
#define plld(x) printf("%lld", (x))
#define plldn(x) printf("%lld\n", (x))
#define sllf(x) scanf("%llf", &(x))
#define pllf(x) printf("%.9llf", (x))
#define pllfn(x) printf("%.9llf\n", (x))
#define sch(x) scanf("%c", &(x))
#define pch(x) printf("%c", (x))
#define pchn(x) printf("%c\n", (x))
#define gtl(x) getline(cin, (x))
#define flsh fflush(stdout)
#define sws ios_base::sync_with_stdio(false); cin.tie(0)
#define gcd __gcd
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define sz(a) (int)((a).size())
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

ll modx(ll Base, ll exponent)
{
	ll ans = 1;
	if(Base == 1)
		return Base;
	while(exponent)
	{
		if(exponent & 1)
			ans = (ans * Base)%mod;
		Base = (Base * Base)%mod;
		exponent = exponent >> 1;
	}
	return ans;
}

ll inmodx(ll num)
{
	return (modx(num, mod-2LL));
}

bool cmp()//true for a before b
{
	bool ans = 0;
	return ans;
}

struct ST_Node
{

	ST_Node()
	{

	}
	void assign_value_()
	{

	}
	void merge_nodes_()
	{

	}
};

const int N = (1e5) + 9;
const int M = (N<<2) + 9;
const int LOGN = ((int)log2(N)) + 3;
const int LOGM = ((int)log2(M)) + 3;

pli p[N], temp[N];
int par[N], cnt[N];
priority_queue < pair < ll, pii > > pq;

int root(int cur)
{
	while(par[cur] != cur)
		cur = par[cur];
	return par[cur];
}

void merge(int a, int b)
{
	if(cnt[a] >= cnt[b])
	{
		par[b] = a;
		cnt[a]+=cnt[b];
	}
	else
	{
		par[a] = b;
		cnt[b]+=cnt[a];
	}
	return;
}

int main()
{
	sws;
	// clock_t clk;
	// clk = clock();
	// io_file;
	// srand (time(NULL));

	//Code here
	int n, i, a, b;
	ll ans = 0LL;
	pair < ll , pii > t;
	cin >> n;
	fo(i,1,n+1)
	{
		par[i] = i;
		cnt[i] = 1;
		cin >> p[i].F >> p[i].S;
	}
	fo(i,1,n+1)
		temp[i] = mp(p[i].F,i);
	sort(temp+1,temp+n+1);
	fo(i,2,n+1)
		pq.push(mp(-(temp[i].F-temp[i-1].F),mp(temp[i].S,temp[i-1].S)));
	fo(i,1,n+1)
		temp[i] = mp(p[i].S,i);
	sort(temp+1,temp+n+1);
	fo(i,2,n+1)
		pq.push(mp(-(temp[i].F-temp[i-1].F),mp(temp[i].S,temp[i-1].S)));
	while(!pq.empty())
	{
		t = pq.top();
		pq.pop();
		a = root(t.S.F);
		b = root(t.S.S);
		if(a != b)
		{
			ans -= t.F;
			merge(a,b);
		}
	}
	cout << ans;
	// Code ends here

	// clk = clock() - clk;
	// cout << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
	return 0;
}