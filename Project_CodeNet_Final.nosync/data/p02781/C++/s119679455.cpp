#include <bits/stdc++.h>
typedef long long       ll;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define f first
#define s second
#define fore(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define forr(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);

double ex[1010];

ll nck(ll a, ll b)
{
	if (a < b) return 0;
	if (a == b) return 1;
	if (b <= 1) return a;
	return nck(a-1, b-1) + nck(a-1, b);
}

ll dp[110][3][2];
string s;

ll f(ll dig, ll k, bool less)
{
	if (dig == -1) return (k == 0);
	if (k == 0) return 1;
	ll &res = dp[dig][k][less];
	if (res != -1) return res;
	res = 0;
	if (less == true) 
		res = 9LL*f(dig-1, k-1, true) + f(dig-1, k, true);
	else if (s[dig] > '0')
	{
		res = (ll(s[dig]-'0')-1)*f(dig-1, k-1, true) + f(dig-1, k-1, false) + f(dig-1, k, true);
	}
	else
	{
		res = f(dig-1, k, less);
	}
	//cout << dig << "," << k << "," << less << " = " << res << endl;
	return res;
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    clr(dp, -1);
    cin >> s;
    ll n = s.size();
    ll k;
    cin >> k;
    assert(s[0] != '0');
    ll res = 0;
    reverse(all(s));
    res = f(n-1, k, false);
    cout << res << '\n';
    return 0;
}
// PLUS ULTRA!