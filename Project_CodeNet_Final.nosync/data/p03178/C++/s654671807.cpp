#include "bits/stdc++.h"

#define ll long long 
#define rep(i,n) for(int i=0;i<n;i++)
#define MX 100005
#define M 1000000007

using namespace std;

int main(){
    string  K;
    cin>>K;
    int D;
    ll d[101][2];
    memset(d,0,sizeof(d));
    cin>>D;
    rep(i,K[0]-'0')d[i%D][0]++;
    int m=K[0]-'0';
        m%=D;
    rep(i,K.size()){
        if(i==0)i++;
        rep(j,D){
            d[j][i%2]=0;
            rep(k,10)d[j][i%2]+=d[(j-k+D*10)%D][(i-1)%2];
            //cout<<d[j][i%2]<<" "<<i<<":"<<j<<"   ";
            d[j][i%2]%=M;
        }
        if(K[i]!='0')rep(k,K[i]-'0')d[(m+k)%D][i%2]++;
        m+=K[i]-'0';
        m%=D;
        //cout<<d[0][i%2]<<" "<<i<<":"<<0<<"   ";
    }
    ll ans=d[0][(K.size()-1)%2];
    ans--;
    if(m==0)ans++;
    ans%=M;
    cout<<ans<<endl;
    return 0;
}