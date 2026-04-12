#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<bits/stdc++.h>
using namespace __gnu_pbds; 
using namespace std;

#define reset(X) memset(X, 0, sizeof(X))
#define int long long
typedef long long ll;
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define all(X) X.begin(),X.end()

const int INF=1e9;
const int mod=1e9+7;
const int mod2=998244353;


#define readn(a) int a;cin>>a;
#define readv(a,n) vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];
#define reada(a,n,m) int a[n][m];for(int i=0;i<n;i++)for(int j=0;j<m;j++) cin>>a[i][j];


#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define map unordered_map
typedef vector<int> vi;
typedef pair<int, int> pii;
int pow(int a, int b)
{
    int prod=1;
    int mult=a;
    while(b!=0)
    {
        if(b%2)
        {
            prod*=mult;
            prod%=mod2;
        }
        mult*=mult;
        mult%=mod2;
        b/=2;
    }
    return prod;
}
int mod_inv(int q, int mod)
{
    return pow(q, mod-2);
}
const int MAXN=1e3+10;
int pdp[MAXN][4][2];
int dp(string s, int i, int k, bool is_small)
{    if(k<0)
        return 0;
    if(pdp[i][k][(is_small?1:0)]!=-1)
        return pdp[i][k][(is_small?1:0)];
;
    if(i==s.size())
    {
        if(k==0)
        return 1;
        else
            return 0;
    }
    int mx=s[i]-'0';
    if(is_small)
        mx=9;
    int &ans=pdp[i][k][(is_small?1:0)];
    ans=0;
    for(int j=0;j<=mx;j++)
    {
        if(j!=0)
        ans+=dp(s, i+1, k-1, is_small||(mx!=j));

        else

        ans+=dp(s, i+1, k, is_small||(mx!=j));
    }
    return ans;
}
signed main()
{

  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    if (fopen("INPUT.txt", "r")) {
        freopen ("INPUT.txt" , "r" , stdin);
        freopen ("OUTPUT.txt" , "w" , stdout);
        freopen ("OUTPUT_ERROR.txt" , "w" , stderr);
    }
    #endif
//---------------------------------------------------------------------------------------------------
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<2;k++)
                pdp[i][j][k]=-1;
    int n, k;
    string s;
    cin>>s>>k;
    cout<<dp(s, 0, k, false);
}