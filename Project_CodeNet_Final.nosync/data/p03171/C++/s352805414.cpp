#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define rev(r) reverse(r.begin(),r.end())
#define SORT(ar) sort(ar.begin(), ar.end())
#define sz(x) (int)(x).size()
#define len(x) (int)x.length()
#define in(a) scanf("%d",&a)
#define pr(x) printf("%d ",x)
#define endl '\n'
#define read(v,n) for(int h=0;h<n;h++) cin>>v[h];
#define fo(i,a,b) for(i=a;i<b;i++)
#define fi(i,a,b) for(i=a;i>=b;i--)
#define mo 1000000007
#define N 300007
ll dp[3000][3000];

int main()
{
    ll n,i,j,k;
    cin>>n;
    ll a[n];
    fo(i,0,n) cin>>a[i];
    fi(i,n-1,0)
    {
        fo(j,i,n)
        {
            if(j==i) dp[i][j]=a[i];
            else dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}
