#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define inf 1000000000000000007
#define eps 0.000001
#define pi 3.141592653589793
#define pii pair<int , int>
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vii vector<int>
#define vpl vector<pll>
#define vll vector<ll>
#define sti stack <int>
#define stll stack <ll>
#define mseti set <ll>
#define msetd multiset <ll, greater <ll> >
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound 
#define stp setprecision(20)//use fixed before stp
#define endl '\n'
ll a[3001][3001];
int main()
{  
    FAST
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[0][i];
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<(n-i);j++)
        {
            a[i][j]=max((a[0][j+i]-a[i-1][j]),(a[0][j]-a[i-1][j+1]));
        }
    }
    cout<<a[n-1][0];
}