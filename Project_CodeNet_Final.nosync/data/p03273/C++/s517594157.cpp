#include<bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define FO freopen("in.txt", "r", stdin)
#define FC freopen("out.txt", "w", stdout)
#define aise cout<<"aise"<<endl
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define ll long long
#define all(x) x.begin(), x.end()
#define mset(v, a) memset(v, a, sizeof(v))
#define pll pair< ll, ll >
#define pdd pair< double, double >
#define ff first
#define ss second
#define pi acos(-1.0)
#define mxN 2010
#define inf 1e14
#define MOD 1000000007

int main()

{

    ll n, m;
    cin >> n >> m;
    ll r = 0, c = 0;
    char ara[n][m];
    for(ll i = 0; i < n; i++)
    {

        for(ll j = 0; j < m; j++) cin >> ara[i][j];
    }
    map<ll,ll> rs,cs;
    for(ll i = 0; i < n; i++)
    {

        r = 0;
        for(ll j = 0; j < m; j++)
        {

            if(ara[i][j]=='.') r++;
        }
        if(r==m) rs[i] = 1;
    }
    for(ll i = 0; i < m; i++)
    {

        c = 0;
        for(ll j = 0; j < n; j++)
            if(ara[j][i]=='.') c++;
        if(c == n) cs[i]=1;
    }
    for(ll i  =0; i < n; i++)
    {

        if(rs[i]==1) continue;
        for(ll j = 0; j < m; j++)
        {

            if(cs[j]==1) continue;
            cout << ara[i][j];
        }
        cout << endl;
    }
}
