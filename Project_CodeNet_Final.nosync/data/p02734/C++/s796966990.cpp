#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double
 
int mod = 998244353;
int n,s;
int arr[3005];
int cache[3005][3005];

int dp(int pos,int sum)
{
    if(sum==s)
        return n-pos+1;

    if(pos==n || sum>s)
        return 0;

    int &ans=cache[pos][sum];
    if(ans!=-1)
        return ans;

    ans=dp(pos+1,sum)+dp(pos+1,sum+arr[pos]);
    ans%=mod;
    return ans;
}
int32_t main() 
{
    IOS;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(cache,-1,sizeof(cache));
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=dp(i,0);
    ans%=mod;
    print(ans);
}   