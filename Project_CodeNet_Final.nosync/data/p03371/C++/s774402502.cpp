#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
ll a,b,c,x,y;
int main(){
	cin >> a >> b >> c >> x >> y;

	ll p = c * max(x * 2,y * 2);
	ll q = c * x * 2 + b * max(0ll,y - x);
	ll r = c * y * 2 + a * max(0ll,x - y);
	ll s = a * x + b * y;
	cout << min(min(p,s),min(q,r)) << endl;
	return 0;
}
