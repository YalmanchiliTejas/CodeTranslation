#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
int MOD=1000000007;
signed main(){
    int n,k;cin>>n>>k;
    int res=0;
    rep1(i,n){
        if(i<=k)continue;
        res+=(n/i)*(i-k)+max((int)0,(n%i)-k+1);
    }
    if(k==0)res=n*n;
    cout<<res<<endl;
    return 0;
}