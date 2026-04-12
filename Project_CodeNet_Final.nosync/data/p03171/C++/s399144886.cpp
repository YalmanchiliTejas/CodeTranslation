#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <ll, ll> pll;
const ll M=1e9+7;
ll inf=1e18;
int main()
{
    fast;
    int n;
    cin>>n;
    vector <ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    ll dp[n][n];
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l==r)
                dp[l][r]=v[l];
            else
                dp[l][r]=max(v[l]-dp[l+1][r],v[r]-dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1];
}
