#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const int64_t LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

struct Combination{
    const int MAX=5000010;
    const int MOD;
    vector<long long> FAC;
    vector<long long> INV;
    vector<long long> FAC_INV;
    Combination(const int MOD):
        MOD(MOD)
        {
            FAC=vector<long long>(MAX);
            INV=vector<long long>(MAX);
            FAC_INV=vector<long long>(MAX);
            FAC[0]=INV[1]=FAC_INV[0]=1;
            for(int i=1;i<MAX;i++){
                FAC[i]=FAC[i-1]*i%MOD;
                if(i>1) INV[i]=MOD-INV[MOD%i]*(MOD/i)%MOD;
                FAC_INV[i]=FAC_INV[i-1]*INV[i]%MOD;
            }
        }
    int C(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return FAC[n]*FAC_INV[r]%MOD*FAC_INV[n-r]%MOD;
    }
    int P(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return FAC[n]*FAC_INV[n-r]%MOD;
    }
    int H(int n,int r){
        if(r==0) return 1;
        return C(n+r-1,r);
    }
};

using fint64 = int_fast64_t;
template<fint64 MOD>
struct ModInt{
    fint64 x;
    ModInt():x(0){}
    ModInt(fint64 x):
        x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)
        {}
    // 負号
    ModInt operator -() const{
        return ModInt(-x);
    }
    // 加算
    ModInt &operator +=(const ModInt &rhs){
        x+=rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator +(const ModInt &rhs) const{
        return ModInt(*this)+=rhs;
    }
    // 減算
    ModInt &operator -=(const ModInt &rhs){
        x+=MOD-rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator -(const ModInt &rhs) const{
        return ModInt(*this)-=rhs;
    }
    // 乗算
    ModInt &operator *=(const ModInt &rhs){
        x*=rhs.x;
        if(x>=MOD) x%=MOD;
        return (*this);
    }
    ModInt operator *(const ModInt &rhs) const{
        return ModInt(*this)*=rhs;
    }
    // 除算
    ModInt &operator /=(const ModInt &rhs){
        (*this)*=rhs.inverse();
        return (*this);
    }
    ModInt operator /(const ModInt &rhs) const{
        return ModInt(*this)/=rhs;
    }
    // 等号
    bool operator ==(const ModInt &rhs){
        return x==rhs.x;
    }
    bool operator !=(const ModInt &rhs){
        return x!=rhs.x;
    }
    // 累乗
    ModInt pow(fint64 n){
        fint64 tmp=x;
        x=1;
        while(n>0){
            if(n&1) x=x*tmp%MOD;
            tmp=tmp*tmp%MOD;
            n>>=1ll;
        }
        return (*this);
    }
    // 逆元
    ModInt inverse(){
        fint64 a=x,b=MOD,s=1,t=0;
        while(b>0){
            fint64 u=a/b;
            a-=u*b;
            s-=u*t;
            swap(a,b);
            swap(s,t);
        }
        return ModInt(s);
    }
    // 入出力
    friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){
        fint64 x; lhs>>x;
        rhs=ModInt<MOD>(x);
        return lhs;
    }
    friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){
        return lhs<<rhs.x;
    }
};

int main(){
    int y,x,k; cin>>y>>x>>k;
    Combination com(MOD);
    using mint=ModInt<MOD>;
    mint ans=0;
    // y
    for(int d=1;d<y;d++){
         // 距離dの置き方
         mint sum=(y-d)*x*x;
         // 各配置に対する組み合わせ
         sum*=com.C(y*x-2,k-2);
         ans+=sum*d;
    }
    // x
    for(int d=1;d<x;d++){
         // 距離dの置き方
         mint sum=(x-d)*y*y;
         // 各配置に対する組み合わせ
         sum*=com.C(y*x-2,k-2);
         ans+=sum*d;
    }
    cout<<ans<<endl;
    return 0;
}
