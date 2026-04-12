#include<bits/stdc++.h>
using namespace std;
                       ///****   Hasebul Hassan Chowdhury ***////
#define ms(a,v)        memset(a,v,sizeof a)
#define lll            long long
#define FOR(i,a,b)     for(int i=a;i<=b;i++)
#define fast           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Read           freopen("READ.txt", "r", stdin)
#define Write          freopen("OUTPUT.txt", "w", stdout)
#define INF            1000000007


void solve()
{
    int n;
    cin>>n;
    lll arr[n+3],ans=0;
    lll cum[n+3]={0};
    for(int i=1;i<=n;i++)
    {
    	cin>>arr[i];
    	cum[i]=(cum[i-1])+(arr[i]);
    }
    for(int i=1;i<=n;i++)
    {
       lll num=cum[n]-cum[i];
       num%=INF;
       lll X=(num)*(arr[i]);
       X%=INF;
       ans+=X;
       ans%=INF;
    }
    cout<<ans<<endl;
}

int main()
{
    fast
    #ifndef ONLINE_JUDGE
    Read;
    Write;
    #endif
    //sieve();
    //int cnt=1;
    //int t; cin>>t; while(t--) solve();
    solve();
}