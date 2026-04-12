#include<bits/stdc++.h>
#include<cmath>
#define pb push_back
#define ld long double
#define mp make_pair
#define vl vector<ll> 
#define vd vector<double>
#define vld vector<long double>
#define ll long long int
#define pl pair<ll, ll>
#define all(a) a.begin(), a.end()
#define forr(i, n) for(ll i=0; i<n; i++) 
#define forr1(i, n) for(ll i=1; i<=n; i++)
using namespace std;
const ld PI =3.1415926535897923846;
const ll MOD = 1e9+7;
void solve()
{
    ll n;
    cin>>n;
    vl a(n);
    
    forr(i, n)  cin>>a[i];
    
    vector<vl> dp(n, vl(n, 0));
    for(ll left=n-1; left>=0; left--)
    {
        for(ll right=left; right<n; right++)
        {
               
            if(left==right)
            {
                dp[left][right]=a[left];
            }    
            else 
            {
                dp[left][right]=max(a[left]-dp[left+1][right], a[right]-dp[left][right-1]);
                
            }
            //cout<<left<<" "<<right<<" "<<dp[left][right]<<endl;
        }
    }
    
    cout<<dp[0][n-1];
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}
