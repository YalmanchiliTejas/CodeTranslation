#define TEMPLATE_USED
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(ll)(n);++i)
#define _repe3(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define _rrepe2(i,n) for(ll i=(ll)(n);i>=0;i--)
#define _rrepe3(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);i--)
#define rrepe(...) _overload3(__VA_ARGS__,_rrepe3,_rrepe2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
const ll mod = 1000000007;

ll N;
vl A;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    A = vl(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    solve();
}

// 2 <= N <= 2× 10^5
// 0 <= A_i <= 10^9
// 入力は全て整数

#ifndef TEMPLATE_USED
#include "../template/template.hpp"
#endif

template<int m>
struct MInt{
    //static int m;

    ll x;
    MInt(ll x=0):x((x%m+m)%m){}

    MInt operator-()const{return MInt(-x);}
    MInt operator+(const MInt &p)const{return MInt(*this)+=p;}
    MInt operator-(const MInt &p)const{return MInt(*this)-=p;}
    MInt operator*(const MInt &p)const{return MInt(*this)*=p;}
    MInt operator/(const MInt &p)const{return MInt(*this)/=p;}

    MInt &operator+=(const MInt &p){
        if((x+=p.x)>=m)x-=m;
        return *this;
    }
    MInt &operator-=(const MInt &p){
        if((x+=m-p.x)>=m)x-=m;
        return *this;
    }
    MInt &operator*=(const MInt &p){
        (x*=p.x)%=m;
        return *this;
    }
    MInt &operator/=(const MInt &p){
        return *this*=p.inv();
    }

    MInt pow(ll n)const{
        MInt ret(1),mul(x);
        while(n){
            if(n&1)ret*=mul;
            mul*=mul;
            n>>=1;
        }
        return ret;
    }
    MInt inv()const{
        //return pow(m-2);
        int a=x,b=m,u=1,v=0,t;
        while(b){
            t=a/b;
            swap(a-=t*b,b);
            swap(u-=t*v,v);
        }
        return MInt(u);
    }

    friend ostream& operator<<(ostream& os,const MInt& a) {return os<<a.x;}
};
//int MInt::m=0;
using mint=MInt<mod>;

// ll N, vl A
// \sum_{i=1}^{N-1}\sum_{j=i+1}^{N} A_i A_j を \bmod (10^9+7) で出力せよ。
void solve(){
    mint sum=0;
    rep(i,N)sum+=A[i];
    sum*=sum;
    rep(i,N)sum-=A[i]*A[i];
    sum/=2;
    cout<<sum<<endl;
}
