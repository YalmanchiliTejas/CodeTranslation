#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using Tu = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;

ll MAX=200001;
vector<ll> F(MAX,1);
 
void fact(){
    for(ll i=1;i<MAX;i++){
    F[i]=F[i-1]*i%MOD;
    }
return;
}


// mod. m での a の逆元 a^{-1} を計算する
//ただしmとaが互いにその時のみ
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

long long comb(long long a, long long b){
    return (((F[a]*modinv(F[b],MOD))%MOD)*modinv(F[a-b],MOD))%MOD;
}

//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓
//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓
//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓
//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓
//↓↓↓↓↓↓fact()ってちゃんとつける！！！！！！！！！！！↓↓↓↓↓↓


int main(){
    fact();
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    ll K;
    cin >> K;

    //x座標だけを見た、和
    ll X=0;
    //Y座標だけを見た和
    ll Y=0;

    //X 
    for(ll i=1;i<=M-1;i++){
        X+=i*N*N*(M-i)%MOD;
        X%=MOD;
    ;}
    //Y
    for(ll i=1;i<=N-1;i++){
        Y+=i*M*M*(N-i)%MOD;
        Y%=MOD;
    ;}

    ll j=(((X+Y)%MOD)*comb(N*M,K))%MOD;
    j%=MOD;
    ll h=modinv(comb(N*M,2),MOD)%MOD;
    h%=MOD;
    ll i=(K*(K-1)/2)%MOD;

    cout<<((j*h%MOD)*i)%MOD<<endl;



    return 0;
}
