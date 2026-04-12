#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
ll mod=pow(10,9)+7;

int main(){
    string K;cin>>K;
    int D,N=K.size();cin>>D;
    mat dp0(2,vec(D)),dp1(2,vec(D));
    //初期化
    for(int j=0;j<D;j++){
        dp0[0][j]=dp1[0][j]=0;
    }
    dp0[0][0]=1;
    //漸化式
    for(int i=1;i<=N;i++){
        for(int j=0;j<D;j++){
            int k=K[i-1]-'0';
            dp0[1][j]=dp0[0][(j-k+10*D)%D];
            ll rev=0;
            for(int l=0;l<10;l++){
                rev=(rev+dp1[0][(j-l+10*D)%D])%mod;
            }
            for(int l=0;l<k;l++){
                rev=(rev+dp0[0][(j-l+10*D)%D])%mod;
            }
            dp1[1][j]=rev;
        }
        dp0[0]=dp0[1];dp1[0]=dp1[1];
    }
    ll ans=(dp0[0][0]+dp1[0][0]-1+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}