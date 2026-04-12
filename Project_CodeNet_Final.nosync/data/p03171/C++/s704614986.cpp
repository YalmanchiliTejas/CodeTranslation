#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define nl printf("\n")
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,st,en) for(i=st;i<=en;i++)
#define repv(i,en,st) for(i=en;i>=st;i--)
#define fout cout<<fixed<<setprecision(7)
#define bi(n) __builtin_popcount(n)
#define bil(n) __builtin_popcountll(n)


typedef long long ll;
typedef pair<int,int> pii;
const int N = 3010;
ll mod = 1e9+7;
ll fmod(ll b,ll exp){
    ll res =1;
    while(exp){if(exp&1ll)res=(res*b)%mod;
    b =(b*b)%mod;exp/=2ll;
    }
    return res;
}
ll A[N];
ll dp[N][N];


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1,n,i,j,m;
    cin>>n;
    rep(i,1,n)cin>>A[i];
    rep(i,1,n)dp[i][1]=A[i];
    rep(i,1,n-1)dp[i][2]=(max(A[i],A[i+1])-min(A[i],A[i+1]));
    rep(j,3,n)
    {
        rep(i,1,n-j+1)
        {
            int en = i+j-1;
            dp[i][j]= max(A[i]-dp[i+1][j-1],A[en]-dp[i][j-1]);
        }
    }
    cout<<dp[1][n]<<"\n";

    
    return 0;
}
