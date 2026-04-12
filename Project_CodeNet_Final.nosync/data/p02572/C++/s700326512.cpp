#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define FT() int t; scanf("%d",&t); while(t--)
#define pb push_back
#define nl printf("\n")
#define fi(i,start,end) for(int i=start; i < (int)end ; ++i)
#define ip(n)   scanf("%d",&n)
#define mz(a)   memset(a,0,sizeof(a))
#define inpArr(A,n) fi(i,0,n)   ip(A[i]);
#define print(a)  for(auto i : a)   cout<<i<<" "; nl;
#define Fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
ll max(ll a,ll b)   {return a>b?a:b;}
ll min(ll a,ll b)   {return a<b?a:b;}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:/Sublime/Rough/input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    //std::cout << std::fixed;
    //std::cout << std::setprecision(6);
    Fastio;
    int testcase = 1;
//    cin>>testcase;
    while(testcase--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll dp[n];
        dp[n-1] = a[n-1];
        for(int i=n-2;i>=0;--i)
            dp[i] = dp[i+1] + a[i];

        ll sm = 0;
        for(int i=0;i<n-1;i++)
            {sm+= ((a[i]%mod)*(dp[i+1]%mod))%mod;
             sm%=mod;}
        cout<<sm;

    }

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s";
    #endif
    
    return 0;
}