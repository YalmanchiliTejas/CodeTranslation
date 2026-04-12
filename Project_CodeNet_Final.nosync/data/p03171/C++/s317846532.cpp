#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mod 1000000007
#define wi while
#define vl vector<ll>
#define vi vector<int>
#define map map<char,ll>
#define endl "\n"
const int mxN = 3002;
ll dp[mxN][mxN];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int l=n-1;l>=0;--l)
    {
        for(int r=l;r<n;++r)
        {
            if(l==r)
            {
                dp[l][r] = a[l];
            }
            else
            {
                dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }

    cout<<dp[0][n-1]<<endl;








    return 0;

}
