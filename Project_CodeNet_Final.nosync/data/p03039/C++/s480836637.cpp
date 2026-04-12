#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 210000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

//http://kmjp.hatenablog.jp/entry/2019/05/26/0900

ll fac[MAX],finv[MAX],inv[MAX];
//http://drken1215.hatenablog.com/entry/2018/06/08/210000
//テーブルを作る前処理　O(n)
//pが素数でなくてはならない
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
//二項係数計算
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}


int main(){
    COMinit();
    int N,M,K;
    cin>>N>>M>>K;
    ll ans=0;
    for(int i=0;i<N;i++){
        ll d=1LL*i*(i+1)/2%MOD;
        d=d*M%MOD*M%MOD;
        ans+=d;
    }
    for(int i=0;i<M;i++){
        ll d=1LL*i*(i+1)/2%MOD;
        d=d*N%MOD*N%MOD;
        ans+=d;
    }
    
    cout<<ans%MOD*COM(N*M-2,K-2)%MOD<<endl;
}

