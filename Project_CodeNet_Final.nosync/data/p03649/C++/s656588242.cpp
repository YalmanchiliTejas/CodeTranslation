#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int n; cin>>n;
    long long a[n]; rep(i,n) cin>>a[i];
    long long ans=0;
    while(1){
        long long cnt[n]={},sum=0;
        rep(i,n){
            cnt[i]=a[i]/n;
            sum+=cnt[i];
        }
        // for(auto i:cnt) cout<<i<<" ";
        // cout<<endl;
        bool flg=1;
        rep(i,n){
            a[i]+=sum-cnt[i]*(n+1);
            if(a[i]>n-1) flg=0;
        }
        // for(auto i:a) cout<<i<<" ";
        // cout<<endl;
        ans+=sum;
        if(flg) break;
    }
    cout<<ans<<endl;
    return 0;
}
