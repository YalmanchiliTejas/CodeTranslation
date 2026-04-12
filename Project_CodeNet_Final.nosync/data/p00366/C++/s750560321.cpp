#include<bits/stdc++.h>
#define V vector
#define VI vector<int>
#define VVI vector<vector<int>>
#define rep(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

VI divisor(int n){
    VI ret;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ret.push_back(i);
            if(i*i!=n)ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

int main(void){
    int N,ans=0;
    cin>>N;
    VI t(N),maxt_d;
    rep(i,N)cin>>t[i];
    sort(t.begin(),t.end());
    maxt_d=divisor(t[N-1]);

    rep(i,N){
        auto ITE=lower_bound(maxt_d.begin(),maxt_d.end(),t[i]); 
        ans+=maxt_d[ITE-maxt_d.begin()]-t[i];
    }
    cout<<ans<<endl;
}



