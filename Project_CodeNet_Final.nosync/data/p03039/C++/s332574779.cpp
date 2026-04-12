#define _GLIBCXX_DEBUG
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;

int P[10010];
void init(int n){
    for(int i=0;i<n;++i)P[i]=i;
}
int root(int a) {
    if(P[a]==a)return a;
    return (P[a]=root(P[a]));
}
bool is_same_set(int a,int b){
    return root(a) == root(b);//代表元を求める
}
void unite(int a,int b){
    P[root(a)]=root(b);
}//対set,グラフ？

double dot_product(xy_t a, xy_t b) { return (conj(a)*b).real(); }//内積
double cross_product(xy_t a, xy_t b) { return (conj(a)*b).imag(); }//外積
xy_t projection(xy_t p, xy_t b) { return b*dot_product(p,b)/norm(b); }//投影
//対図形

#define mod 1000000007
ll f[200001];

//int n,k とかしておく

ll pw(ll x, ll y){//euclidの互除法より
    ll a= 1;
    while(y){
        if(y&1){//奇数なら
            a = a*x%mod;
        }
        x = x*x%mod;
        y /= 2;
    }
    return a;
}

ll modinv(ll x){//逆元を求める
    return pw(x, mod - 2 );
}

ll comb(int n,int r){
    if(n<r){
        return 0;
    }
    return f[n] * modinv(f[r])%mod*modinv(f[n-r])%mod;
}//対combination


int main(){
    int n,m,k;
    f[0]=1;
    rep2(i,200000){
        f[i]=f[i-1]*i%mod;
    }
    cin >> n >> m >> k;
    ll c= comb(n*m-2,k-2)%mod;//２マスの組み合わせを固定した場合の残りの組み合わせ
    ll ans=0;
    rep(d,n){
        ll num=(n-d)*m*m%mod;//xの絶対値の差がdになるような２マスの選び方
        ans=(ans+d*num%mod)%mod;
    }
    rep(d,m){
        ll num=(m-d)*n*n%mod;
        ans=(ans+d*num%mod)%mod;//y同上
    }
    ans*=c;
    ans%=mod;
    cout<< ans<< endl;
    return 0;
}