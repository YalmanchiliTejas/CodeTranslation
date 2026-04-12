#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define ALL(c) (c).begin(),(c).end()
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define SZ(x) (x).size();
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define INF 1e18
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
void solve();

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main() {
	fastio;
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

	int t;
	t=1;

    //cin>>t;
	while (t--)
	{
		solve();
	}
	return 0;
}

ll calc(ll a[],ll i,ll j,vector<vector<ll>> &dp)
{
    if(i>j)
        return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    dp[i][j]=max(a[i]+min(calc(a,i+2,j,dp),calc(a,i+1,j-1,dp)),a[j]+min(calc(a,i,j-2,dp),calc(a,i+1,j-1,dp)));

    return dp[i][j];
}

void solve()
{
    ll n,i,s=0,k,b;
    cin>>n;

    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }

    vector<vector<ll>> dp(n,vector<ll>(n,-1));

    k=calc(a,0,n-1,dp);
    b=s-k;

    cout<<k-b<<endl;
}
