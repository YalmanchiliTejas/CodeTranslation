#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define inf 1000000000000000007
#define eps 0.000000000001
#define pi 3.141592653589793
#define pii pair<int,int>
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vii vector<int>
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset <ll>
#define msetd multiset <ll, greater <ll> >
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound 
#define stp setprecision(20)//use fixed before stp
#define endl '\n'
int main()
{  
    FAST
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mseti m;
    for(ll i=n-1;i>=0;i--)
    {
        if(m.ub(a[i])==m.end())
        {
            m.insert(a[i]);
        }
        else
        {
            m.erase(m.ub(a[i]));
            m.insert(a[i]);
        }
    }
    cout<<m.size();
}