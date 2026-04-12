#include<bits/stdc++.h>
// Begin Header {{{
#define all(x) (x).begin(), (x).end()
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
//Function
lli combi(lli n, lli r)
{
	if(r==0 || r==n) return 1;
	else return combi(n-1,r) + combi(n-1,r-1);
}
lli sigma1(lli n){return n*(n+1)/2;}
lli sigma2(lli s, lli n){return sigma1(n) - sigma1(s -1);}
using namespace std;
// }}} End Header

lli body(lli a, lli b){
	return (a-b)*(a-b);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int a, b, c, x, y, cost, cost1, cost2, ans;
	cin >> a >> b >> c >> x >> y;
	int k = Max(x, y);
	cost = a*x + b*y;
	cost1 = 2*c*k;
	if(x > y) cost2 = 2*c*y + (x-y)*a;
	else cost2 = 2*c*x + (y-x)*b;
	ans = Min(cost, cost1);
	ans = Min(ans, cost2);
	cout << ans << endl;
 	return 0;
}
