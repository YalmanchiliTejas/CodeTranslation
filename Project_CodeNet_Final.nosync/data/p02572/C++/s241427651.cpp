#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
#define ll long long
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
const ll MOD=1000000007L;
// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
int main(){
    long long N;
    cin>>N;
    ll suma=0;
    ll a2=0;
    ll ans =0;
    ll tmp2=0;
    ll suma2=0;
    rep(i,N){
        ll tmp;
        cin>>tmp;
        tmp2=(tmp*tmp)%MOD;
        a2=a2+tmp2;
        suma=suma+tmp;
        a2=a2%MOD;
        suma=suma%MOD;
    }
    if(suma<0){
        suma=suma+MOD;
    }
    if(a2<0){
        a2=a2+MOD;
    }
    suma2=(suma*suma)%MOD;
    ans=(suma2-a2)%MOD;
    if(ans<0){
        ans=ans+MOD;
    }
    //正しい答え*2%MOD=ansになるようなやつが正しい答え
    ll ans2=0;
    ll inv2=modinv(2,MOD);
    ans2=(ans*inv2)%MOD;
    //(ans2*2)%MOD=ansなるans2が答え
    if(ans2<0){
        ans2+MOD;
    }
    cout << ans2 << endl;
    return 0;
}