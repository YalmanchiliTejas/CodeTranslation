//written by libra9z
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for (int i=0;i<(n);i++)
#define repit(it,a) for (__typeof(a.begin()) it=a.begin();it!=a.end();++it)
#define RET(p,x) return p<<x<<endl,0
#define all(a) (a).begin(),(a).end()
#define reunique(v) v.erase(unique(all(v)),v.end())
#define sz(a) (int)a.size()
#define sqr(x) ((x)*(x))
const int inf=1e9;
const ll lnf=1e18;
const int mod=1e9+7;
const int Maxn=2e5+5;
int n,sum;
int a[Maxn],b[Maxn];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie();cout.tie();
	cout<<setprecision(15);
	cin>>n;
	for (int i=1;i<=n;++i) cin>>a[i],b[i]=a[i];
	sort(a+1,a+n+1);
	int k=(n+1)/2;
	for (int i=1;i<=n;++i)
	{
		if (b[i]<=a[k])
		{
			cout<<a[k+1]<<endl;
		}
		else cout<<a[k]<<endl;
	}
	return 0;
}