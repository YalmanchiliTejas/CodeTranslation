/*SorooshH*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> tpi;
typedef pair<pii,pii> qpi;
const int MAX = 1e5;
const int MV = 1e5;
const int MOD = 1e9 + 7;
const int INF = 2e9;
ll MA = -INF , MI = INF , ANS;

ll n , k , m;
ll a , b , c , d;
int32_t main()
{
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> k;

    if( k == 0 )
        return cout << n*n , 0;

    for(ll i=k+1 ; i<=n ; i++)
    {
        ANS += (i-1) - (k-1);
        m = n-i+1;
        a = m/i;
        b = i-k;
        c = m - (a*i);
        d = max(0ll,c-k);
        ANS += d + (a*b);
    }

    cout << ANS << "\n";
    return 0;
}
