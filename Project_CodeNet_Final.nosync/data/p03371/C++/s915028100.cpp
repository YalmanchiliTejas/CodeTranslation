#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;

ll a, b, c, x, y;

int main() {
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
	ll p1 = 2 * c * max(x,y);
	ll p2 = (a * x) + (b * y);
	ll p3 = (2 * c * min(x, y));
	if (x > y) {
		p3 += (x-y) * a;
	} else if(x<y) p3 += (y - x) * b;
	printf("%lld",min(p1,min(p2,p3)));
}