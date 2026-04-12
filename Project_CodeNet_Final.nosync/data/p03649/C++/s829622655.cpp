#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)

#define clong(d) scanf("%lld", &d)
#define clong2(a, b) scanf("%lld %lld", &a, &b)
#define clong3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define clong4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define revforeach(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long int slong;
typedef pair<int, int> pii;
typedef pair<slong, slong> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

#ifdef VSP4 
    #include "debug.h"    
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;

const int MAXN = 50;
const int SQRTN = 550;
const int LOGN = 60;
const int INT_INFINITY = 1001001001;
const int LIMIT = 40000;

const slong LONG_INFINITY = 1001001001001001001ll;
const slong LONG_LIMIT = 200100100100101ll;

slong k;
const slong MAXLIM = 5ll*1000*1000*1000*1000*100000;
const slong MAXVAL = 1ll*1000*1000*1000*1000*10000 + 1000;

int n;
slong arr[MAXN+5];

int main()
{
	#ifdef VSP4
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	cout.tie(0);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int t, i, j, u, v;
	
	cint(n);
	
	for (i = 1; i <= n; i++)
	{
		clong(arr[i]);
	}
	
	slong count = 0;
	
	while (true)
	{
		bool found = false;
		
		slong maxi = *max_element(arr+1, arr+1+n);
		
		if (maxi < n)
		{
			break;
		}
		
		for (i = 1; i <= n; i++)
		{
			if (arr[i] == maxi)
			{
				slong moves = (arr[i] - (n-1) + n - 1)/n;
				found = true;
				
				arr[i] -= moves*n;
				
				count += moves;
				
				for (j = 1; j <= n; j++)
				{
					if (i != j)
					{
						arr[j] += moves;
					}
				}
				
				break;
			}
		}
		
		if (!found)
		{
			break;
		}
	}
	
	cout << count;
	
	return 0;
}
