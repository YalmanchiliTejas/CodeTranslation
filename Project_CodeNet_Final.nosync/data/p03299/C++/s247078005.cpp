#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD=1e9+7;

template<uint_fast64_t Modulus> class modint{
    using u64=uint_fast64_t;
    public:
    u64 a;
    constexpr modint(const u64 x=0) noexcept:a(((x%Modulus)+Modulus)%Modulus){}
    constexpr u64 &value() noexcept{return a;}
    constexpr const u64 &value() const noexcept{return a;}
    constexpr modint &operator+=(const modint &rhs) noexcept{
        a+=rhs.a;
        if (a>=Modulus) a-=Modulus;
        return *this;
    }
    constexpr modint operator+(const modint &rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint &operator++() noexcept{
        return ++a,*this;
    }
    constexpr modint operator++(int) noexcept{
        modint t=*this; return ++a,t;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{
        if (a<rhs.a) a+=Modulus;
        a-=rhs.a;
        return *this;
    }
    constexpr modint operator-(const modint &rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint &operator--() noexcept{
        return --a,*this;
    }
    constexpr modint operator--(int) noexcept{
        modint t=*this; return --a,t;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        a=a*rhs.a%Modulus;
        return *this;
    }
    constexpr modint operator*(const modint &rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        u64 exp=Modulus-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    constexpr modint operator/(const modint &rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint operator-() const noexcept{
        return modint(Modulus-a);
    }
    constexpr bool operator==(const modint &rhs) const noexcept{
        return a==rhs.a;
    }
    constexpr bool operator!=(const modint &rhs) const noexcept{
        return a!=rhs.a;
    }
    constexpr bool operator!() const noexcept{return !a;}
    friend constexpr modint pow(modint rhs,long long exp) noexcept{
        modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept{
        return modint(x)+y;
    }
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept{
        return modint(x)-y;
    }
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept{
        return modint(x)*y;
    }
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept{
        return modint(x)/y;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept{
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,modint &rhs) noexcept{
        u64 a; rhs=modint{(s >> a,a)}; return s;
    }
};

using mint=modint<MOD>;

template<class K>
struct Matrix{
    vector<vector<K>> dat;
    Matrix(size_t r,size_t c):dat(r,vector<K>(c,K())){}
    Matrix(size_t n):dat(n,vector<K>(n,K())){}
    Matrix(vector<vector<K>> dat):dat(dat){}
    size_t size() const{return dat.size();}
    vector<K> &operator[](int i){return dat[i];}
    const vector<K> &operator[](int i) const{return dat[i];}
    static Matrix I(size_t n){
        Matrix res(n);
        for (int i=0;i<n;++i) res[i][i]=K(1);
        return res;
    }
    Matrix &operator+=(const Matrix &B){
        for (int i=0;i<dat.size();++i)
            for (int j=0;j<dat[0].size();++j)
                (*this)[i][j]+=B[i][j];
        return (*this);
    }
    Matrix operator+(const Matrix &B) const{
        return Matrix(*this)+=B;
    }
    Matrix &operator-=(const Matrix &B){
        for (int i=0;i<dat.size();++i)
            for (int j=0;j<dat[0].size();++j)
                (*this)[i][j]-=B[i][j];
        return (*this);
    }
    Matrix operator-(const Matrix &B) const{
        return Matrix(*this)-=B;
    }
    Matrix &operator*=(const Matrix &B){
        vector<vector<K>> res(dat.size(),vector<K>(B[0].size(),K()));
        for (int i=0;i<dat.size();++i)
            for (int j=0;j<B[0].size();++j)
                for (int k=0;k<B.size();++k)
                    res[i][j]+=(*this)[i][k]*B[k][j];
        dat.swap(res);
        return (*this);
    }
    Matrix operator*(const Matrix &B) const{
        return Matrix(*this)*=B;
    }
    Matrix &operator^=(long long k){
        Matrix res=Matrix::I(size());
        while(k){
            if (k&1LL) res*=*this;
            *this*=*this; k>>=1LL;
        }
        dat.swap(res.dat);
        return (*this);
    }
    Matrix operator^(long long k) const{
        return Matrix(*this)^=k;
    }
    static Matrix Gauss_Jordan(const Matrix &A,const Matrix &B){
        int n=A.size(),l=B[0].size();
        Matrix C(n,n+l);
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j)
                C[i][j]=A[i][j];
            for (int j=0;j<l;++j)
                C[i][j+n]=B[i][j];
        }
        for (int i=0;i<n;++i){
            int p=i;
            for (int j=i;j<n;++j){
                if (abs(C[p][i])<abs(C[j][i])) p=j;
            }
            swap(C[i],C[p]);
            if (abs(C[i][i])<1e-9) return Matrix(0,0);
            for (int j=i+1;j<n+l;++j) C[i][j]/=C[i][i];
            for (int j=0;j<n;++j){
                if (i!=j) for (int k=i+1;k<n+l;++k){
                    C[j][k]-=C[j][i]*C[i][k];
                }
            }
        }
        Matrix res(n,l);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                res[i][j]=C[i][j+n];
        return res;
    }
    Matrix inv() const{
        Matrix res=I(size());
        return Gauss_Jordan(*this,res);
    }
    K determinant() const{
        Matrix A(dat);
        K res(1);
        int n=size();
        for (int i=0;i<n;++i){
            int p=i;
            for (int j=i;j<n;++j){
                if (abs(A[p][i])<abs(A[j][i])) p=j;
            }
            if (i!=p) swap(A[i],A[p]),res=-res;
            if (abs(A[i][i])<1e-9) return K(0);
            res*=A[i][i];
            for (int j=i+1;j<n;++j) A[i][j]/=A[i][i];
            for (int j=i+1;j<n;++j)
                for (int k=i+1;k<n;++k)
                    A[j][k]-=A[j][i]*A[i][k];
        }
        return res;
    }
    //sum_{k=0}^{n-1} x^k
    static K geometric_sum(K x,long long n){
        Matrix A(2);
        A[0][0]=x; A[0][1]=0;
        A[1][0]=1; A[1][1]=1;
        return (A^n)[1][0];
    }
    //sum_{k=0}^{n-1} A^k
    Matrix powsum(long long k) const{
        int n=size();
        Matrix B(n<<1),res(n);
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j)
                B[i][j]=dat[i][j];
            B[i+n][i]=B[i+n][i+n]=K(1);
        }
        B^=k;
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                res[i][j]=B[i+n][j];
        return res;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> h(N+2);
    h[0]=h[N+1]=0;
    for (int i=1;i<=N;++i) cin >> h[i];
    vector<mint> dp(N+2,0);
    dp[0]=1;
    for (int i=1;i<=N;++i){
        dp[i]+=dp[i-1]*2;
        if (h[i]<=h[i-1]) continue;
        ll Min=h[i],sum=0; mint pre=0;
        for (int j=i+1;j<=N+1;++j){
            sum+=max(0LL,h[j]-h[j-1]);
            if (h[j]>=Min) continue;
            ll other=max(h[j],h[i-1]);
            mint rui=Matrix<mint>::geometric_sum((mint)2,h[i]-other-(other==0?1:0));
            dp[j]+=dp[i]*(rui-pre)*pow((mint)2,sum)*(h[j]>0?2:1);
            Min=h[j]; pre=rui;
            if (h[j]<=h[i-1]||h[j]<=1) break;
        }
    }
    cout << dp[N]+dp[N+1] << '\n';
}