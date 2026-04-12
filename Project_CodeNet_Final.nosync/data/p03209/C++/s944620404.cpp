#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

long long dp[55],p[55];
long long search(long long n,long long x){
    // cout<<n<<" "<<x<<endl;
    if(x==dp[n]) return p[n];
    if(x==(dp[n]+1)/2) return p[n-1]+1;
    if(x==1) return 0;
    if(x>(dp[n]+1)/2) return p[n]-search(n,dp[n]-x);
    return search(n-1,x-1);
}
int main(){
    long long n,x; cin>>n>>x;
    dp[0]=p[0]=1;
    for(int i=1;i<55;i++){
        dp[i]=dp[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }
    // cout<<dp[2]<<endl;
    cout<<search(n,x)<<endl;
    return 0;
}
