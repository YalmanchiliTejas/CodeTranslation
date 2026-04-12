#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define mp make_pair
#define ll long long
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2097162
#define inf 1e9
#define MOD 1000000007

int main()
{

    ll n;
    cin >> n;
    ll ans = 0, mx = 0;
    for(ll i = 0; i < n; i++)
    {

        ll x;
        cin >> x;
        if(x >= mx)
        {

            ans++;
            mx = x;
        }
    }
    cout << ans;
    
}
