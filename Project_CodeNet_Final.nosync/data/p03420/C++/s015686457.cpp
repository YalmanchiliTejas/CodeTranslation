#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define reunique(v) v.erase(unique(v.begin(),v.end()),v.end())
#define RET(p,x) return p<<x<<endl,0;
#define Debug(x) cerr<<#x<<" = "<<x<<endl
const int inf=1e9;
const ll h1=239017;
const ll h2=731604233;
const ll mod=1000000007;
const ll mod2=1000000009;
const int dx[]={1,0,-1,0,1,0,-1,0};
const int dy[]={0,1,0,-1,1,0,-1,0};
ll n,k,ans=0;
signed main()
{
	ios_base::sync_with_stdio();cin.tie();cout.tie();
	cout<<setprecision(15);
	cin>>n>>k;
	for (ll i=k+1;i<=n;++i) for (ll j=0;j*i+k<=n;++j) ans+=max(0LL,min(i-k,n-j*i-k+1));
	if (!k) ans-=n;
	cout<<ans<<endl;
	return 0;
}