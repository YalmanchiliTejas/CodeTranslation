#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl
 
#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define INF 1000000000000000000

ll dp1[10001][101];
ll dp2[10001][101];
ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string k;
    ll d;
    cin >> k >> d;

    dp1[0][0] = 1;

    ll n = k.length();

    fr(i,1,n)
    {
        fr(j,0,d-1)
        {
            fr(x,0,9)
            {
                if(x<k[n-i]-'0')
                {
                    dp1[i][j] = (((dp1[i][j])%mod + (dp1[i-1][(j + (10*d) - x)%d])%mod)%mod + (dp2[i-1][(j + (10*d) - x)%d]%mod))%mod;
                }
                else if(x==k[n-i]-'0')
                {
                    dp1[i][j] = ((dp1[i][j]%mod) + (dp1[i-1][(j + (10*d) - x)%d])%mod)%mod;
                    dp2[i][j] = ((dp2[i][j]%mod) + (dp2[i-1][(j + (10*d) - x)%d])%mod)%mod;
                }
                else
                {
                    dp2[i][j] = (((dp2[i][j])%mod + (dp1[i-1][(j + (10*d) - x)%d])%mod)%mod + (dp2[i-1][(j + (10*d) - x)%d]%mod))%mod;
                }
            }

            // cout << dp1[i][j] << " " << dp2[i][j] << " " << i << " " << j << endl;
        }
    }

    cout << (dp1[n][0]-1+mod)%mod << endl;
}