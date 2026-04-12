#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int SET(int N, int pos)  {return N=N | (1<<pos);}
int RSET(int N,int pos)  {return N= N & ~(1<<pos);}
bool CHK(int N,int pos)  {return (bool)(N & (1<<pos));}

#define ll             long long
#define pll            pair<ll,ll>
#define unique(a)      a.resize(unique(a.begin(), a.end()) - a.begin())
#define fill(v, p)     memset(v,p,sizeof v)
#define all(x)         x.begin(), x.end()
#define index(x,i)     x.find_by_order(i)
#define lesscount(x,i) x.order_of_key(i)
#define PI             acos(-1.0)
#define EPS            0.000000001
#define INF            1e18+10
#define MAX            300005
#define MOD            1000000007


signed int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	if(n==m)
	{
		cout << "Yes\n";
	}
	else cout << "No\n";
	
	return 0;
}
