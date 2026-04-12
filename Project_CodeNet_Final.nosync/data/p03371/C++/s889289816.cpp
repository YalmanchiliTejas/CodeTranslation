#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main()
{
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	ll ans = 0;
	if(2*c<a+b)
	{
		int foo = min(x,y);
		ans += foo*2*c;
		x-=foo;
		y-=foo;
	}
	if(2*c<a)
	{
		ans += 2*x*c;
		x=0;
	}

	if(2*c<b)
	{
		ans += 2*y*c;
		y=0;
	}
	ans += a*x;
	ans += b*y;
	cout<<ans<<endl;
	return 0;
}