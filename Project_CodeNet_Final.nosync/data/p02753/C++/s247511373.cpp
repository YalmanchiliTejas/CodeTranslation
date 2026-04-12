// VALUE THE SACRIFICES..
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define out_of_reach ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i < n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define mod 1000000007
// -----------------------------------------------------------------
void solve()
{
    int n,i,j,x,m,k,u,y;
    string s;
    cin>>s;
    j=0;
    rep(i,3)
        if(s[i]=='A')
            ++j;
    if(j==1 || j==2)   cout<<"Yes";
    else    cout<<"No";
}
signed main()
{
    int t=1;
    //  cin>>t;
    string s;
    while(t--)
        solve();
    return 0;
}
