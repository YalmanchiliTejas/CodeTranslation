#include <bits/stdc++.h>

using namespace std;

#define int long long
#define faster ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cint int t;cin>>t;while(t--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vint vector<int>
#define all(v) (v).begin(), (v).end()
#define pii pair<int,int>
#define pb push_back
const int N=3005;

int mod=998244353;

int cache[N][N];
int n;
int a[N];

int dp(int idx,int s){
    if(s==0) return n-idx+1;
    if(s<0) return 0;

    int &ans=cache[idx][s];
    if(idx>n-1) return 0;
    if(ans!=-1) return ans;

    ans=dp(idx+1,s)+dp(idx+1,s-a[idx]);
    ans%=mod;
    return ans;
}

int32_t main() {
    int s;
    cin>>n>>s;
    memset(cache,-1, sizeof(cache));
//    int a[n];
    rep(i,0,n) cin>>a[i];

    int ans=0;

    for(int i=0;i<n;i++){
        ans+=dp(i,s);
//        cout<<ans<<endl;
        ans%=mod;
    }

    cout<<ans<<endl;
}