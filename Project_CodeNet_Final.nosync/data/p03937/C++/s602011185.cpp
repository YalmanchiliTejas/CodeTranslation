#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int LL;
typedef LL ll;
typedef string str;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef stringstream strs;
 
#define X first
#define Y second
#define PB push_back
#define For(i,a,b) for (int i=a;i<b;i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define smax(a,b) a=max(a,b)
#define smin(a,b) a=min(a,b)
#define SZ(a) ((ll)a.size())
#define ER(a) cout << #a << ' ' << a << endl
#define LB(a,n,x) (lower_bound(a,(a)+(n),x)-(a))
#define RET(x) { cout << x; exit(0); } 
const ll M=2e5+5,LG=19,SM=4000+5,inf=1e18+1;
ll mod=924844033;

ll h,w;
ll jad[M];

int main()
{
	ios::sync_with_stdio(0);
	cin >> h >> w;
	For(i,0,h)
	{
	    str s;
	    cin >> s;
	    For(j,0,w)
	    {
	        jad[i+j]+=s[j]=='#';
	    }
	} 
	For(i,0,h+w-1)
	{
	    //ER(jad[i]);
	    if (jad[i]!=1) RET("Impossible");
	}
	RET("Possible");
}    