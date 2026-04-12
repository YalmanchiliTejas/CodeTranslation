#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;

//a^n modをO(logN)で計算
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//a/bをmodで割った余り、フェルマーの小定理
int64_t div(int64_t a,int64_t b,int64_t mod){
    return (a%mod)*(modpow(b,mod-2,mod)%mod)%mod;
}
// a-bをMODで割ったあまり、負にならない工夫
long long sub(long long a,long long b){
    long long ans = ((a%MOD)-(b%MOD))%MOD;
    if(ans>=0){
        return ans;
    }
    else{
        return ans+MOD;
    }
}
int main(){
    int n;
    cin>>n;
    int64_t ajmod=0;
    int64_t ans=0;
    vector<int64_t> a(n);
    rep(i,n)cin>>a[i];
    rep(i,n){
        ajmod += a[i]%MOD;
        ajmod %= MOD;
    }
    rep(i,n){
        ajmod = sub(ajmod,a[i]);
        ans += a[i]*ajmod %MOD;
        ans %= MOD;
    }
    cout<<ans%MOD<<endl;
}