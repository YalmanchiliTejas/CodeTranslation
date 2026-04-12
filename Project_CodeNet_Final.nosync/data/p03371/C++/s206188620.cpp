//header{{{
#include<bits/stdc++.h>
  
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define setout(n,x) setw(n) << setfill(x)
#define Fixed fixed << setprecision(10)
#define int long long
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod = 1e9+7; 
 
int gcd(int a,int b){ return b ? gcd(b,a % b) : a;}
int lcm(int a,int b){ return a / gcd(a,b) * b;}
//}}}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	c *= 2;
	if(x > y) cout << min({a*x + b*y,x * c,y*c + (x-y) * a}) << '\n';
	else cout << min({a*x + b*y,y * c,x*c + (y-x) * b}) << '\n';
	return 0;
}
