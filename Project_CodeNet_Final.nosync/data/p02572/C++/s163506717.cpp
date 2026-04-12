#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%I64d",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define INF                         (int)1e9
#define EPS                         1e-9
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define MOD                         1000000007
typedef long long ll;
/*For you see , each day i love you
 more.Today more than yesterday
  less than tomorrow.*/
using namespace std;

int main()
{
	int n;cin>>n;
	vector<ll> vec;
	ll sum = 0;
	
	for(int i = 0;i<n;i++)
	{
		ll x;cin>>x;
		vec.push_back(x);
		sum+=x;
	}
	
	ll ans = 0;
	
	for(int i = 0;i<n;i++)
	{
		sum-=vec[i];
		ll val = (sum)%MOD;
		val = (vec[i]*val)%MOD;
		ans = (ans + val)%MOD;
	}
	
	cout<<ans<<endl;
	
	return 0;
}