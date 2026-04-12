#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define debug(output) cout<<#output<<"= "<<output<<endl
using lint=long long;
int MOD=1000000007;

signed main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<lint> sm(n+1,0);
    rep1(i,n){
        sm[i]=sm[i-1]+a[i-1];
        sm[i]%=MOD;
    }
    lint res=0;
    for(int i=1;i<n;++i){
        res+=sm[i]*a[i];
        res%=MOD;
    }
    cout<<res<<"\n";
    return 0;
}