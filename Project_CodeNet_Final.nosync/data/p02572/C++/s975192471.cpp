#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,s,f) for(i=s;i<f;i++)
#define print(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define db cout<<"db: "
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define all(v) v.B,v.E
#define sz(v) (int)((v).size())
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define clk1 clock_t start_time=clock()
#define clk2 cout<<(clock()-start_time)/(double)CLOCKS_PER_SEC
#define clean(arr) memset(arr,0,sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)

int main()
{
    int n,i,j,t;
    boost;

    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)cin>>arr[i];
    ll sum = accumulate(arr,arr+n,0ll);
    sum%=mod;
    ll ans=0;
    for(i=0;i<n;i++)
    {
        sum-=arr[i];
        ans+= sum*arr[i];
        sum%=mod;
        ans%=mod;
    }
    ans+=mod;
    ans%=mod;
    cout<<ans;

    return 0;
}