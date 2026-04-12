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

ll n;
ll a[3001];
ll dp[3001][3001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    fr(i,1,n)
    {
        cin >> a[i];
    }

    fr(i,1,n)
    {
        if(n%2)
            dp[i][i][1] = a[i];
        else
            dp[i][i][0] = a[i];
    }

    fr(i,2,n)
    {
        fr(j,1,n-i+1)
        {
            ll x = j;
            ll y = i+j-1;

            ll xx1 = dp[x][y-1][0];
            ll xx2 = dp[x][y-1][1];
            ll xx3 = dp[x+1][y][0];
            ll xx4 = dp[x+1][y][1];

            if(n%2 == i%2)
            {
                ll yy1 = xx2+a[y];
                ll yy2 = xx1;

                ll zz1 = xx4+a[x];
                ll zz2 = xx3;

                if(yy1-yy2 > zz1-zz2)
                {
                    dp[x][y][0] = yy2;
                    dp[x][y][1] = yy1;
                }
                else
                {
                    dp[x][y][0] = zz2;
                    dp[x][y][1] = zz1;
                }
            }
            else
            {
                ll yy1 = xx2;
                ll yy2 = xx1+a[y];

                ll zz1 = xx4;
                ll zz2 = xx3+a[x];

                if(yy1-yy2 > zz1-zz2)
                {
                    dp[x][y][0] = zz2;
                    dp[x][y][1] = zz1;
                }
                else
                {
                    dp[x][y][0] = yy2;
                    dp[x][y][1] = yy1;
                }
            }
        }
    }

    cout << dp[1][n][1]-dp[1][n][0] << endl;
}