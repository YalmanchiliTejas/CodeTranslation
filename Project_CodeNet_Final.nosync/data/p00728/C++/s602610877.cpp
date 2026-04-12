#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;i++)
const ll INF=1e18;
const int inf=2e9;
const ll MOD=1000000007;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};

int main(){
    while(true){
        int N;cin>>N;
        if(N==0)break;
        int info[N];
        rep(i,N)cin>>info[i];
        sort(info,info+N);
        int sum=0;
        rep(i,N-2)sum+=info[i+1];
        int ans=sum/(N-2);
        cout<<ans<<endl;
    }
    return 0;
}
