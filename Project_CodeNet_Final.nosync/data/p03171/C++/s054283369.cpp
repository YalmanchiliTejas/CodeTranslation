#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define forn(a,b,c) for(int a=b;a<=c;a++)
#define ford(a,b,c) for(int a=b;a>=c;a--)
#define f first
#define s second
typedef pair<int,int> pii;
const int N=3e3+5;
const int mod=998244353;
const ll inf=1e18+7;
ll a[N],dp[N][N];int n;
ll calc(int l,int r){
    if(l>r){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    if((l+n-r-1)%2==0){
        return dp[l][r]=max(calc(l+1,r)+a[l],calc(l,r-1)+a[r]);
    }
    return dp[l][r]=min(calc(l+1,r)-a[l],calc(l,r-1)-a[r]);
}
int main()
{
    fill(&dp[0][0], &dp[0][0] + N*N, -1);
    scanf("%d",&n);
    forn(i,0,n-1){
        scanf("%d",&a[i]);
    }
    printf("%lld\n",calc(0,n-1));
    return 0;
}
