#include<bits/stdc++.h>
using namespace std;
#define ar array
#define endl '\n'
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(m) Rep(i,1,m)
#define For(m) Rep(i,0,m-1)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
const ll INF = 1e7;
#define mod 1000000007
 
const int mxN = 3e3 + 1;
ll n, k;
array<ll, 2> dp[mxN][mxN];
ll a[mxN];
 
int main()
{
FIO
 
    cin >> n;
    For(n) cin >> a[i];
    Rev(i,n-1,0)
    {
        dp[i][i] = {a[i], 0};
        Rep(j,i+1,n-1)
        {
            if(dp[i][j-1][1] + a[j] > dp[i+1][j][1] + a[i])
                dp[i][j] = {dp[i][j-1][1] + a[j], dp[i][j-1][0]};
            else
                dp[i][j] = {dp[i+1][j][1] + a[i], dp[i+1][j][0]};

        }
    }

    cout << dp[0][n-1][0] - dp[0][n-1][1] << endl;
}