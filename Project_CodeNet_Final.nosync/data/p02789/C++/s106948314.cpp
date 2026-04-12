#include<bits/stdc++.h>
double PI=acos(-1);
template<typename T>
class FFT{
  private:
    using Complex = std::complex<double>;
    std::vector<Complex> C;
    void DFT(std::vector<Complex> &F,size_t n,int sig=1){
        if(n==1) return;
        std::vector<Complex> f0(n/2),f1(n/2);
        for(size_t i=0;i<n/2;++i){
            f0[i]=F[2*i];
            f1[i]=F[2*i+1];
        }
        DFT(f0,n/2,sig);
        DFT(f1,n/2,sig);
        Complex z(cos(2.0*PI/n),sin(2.0*PI/n)*sig),zi=1;
        for(size_t i=0;i<n;++i){
            if(i<n/2) F[i]=f0[i]+zi*f1[i];
            else F[i]=f0[i-n/2]+zi*f1[i-n/2];
            zi*=z;
        }
        return;
    }
    void invDFT(std::vector<Complex> &f,size_t n){
        DFT(f,n,-1);
        for(size_t i=0;i<n;++i){
            f[i]/=n;
        }
        return;
    }
  public:
    FFT(const std::vector<T> &A,const std::vector<T> &B){
        size_t n=1;
        while(n<=A.size()+B.size()){
            n*=2;
        }
        std::vector<Complex> g(n,Complex(0));
        C.resize(n,Complex(0));
        size_t i_len=std::max(A.size(),B.size());
        for(size_t i=0;i<i_len;++i){
            if(i<A.size()) C[i]=Complex(A[i]);
            if(i<B.size()) g[i]=Complex(B[i]);
        }
        DFT(C,n);
        DFT(g,n);
        for(size_t i=0;i<n;++i) C[i]=C[i]*g[i];
        invDFT(C,n);
        for(size_t i=0;i<n;++i) if(T(C[i].real())!=C[i].real()){
            C[i]=Complex(C[i].real()+0.5);
        }
    }
    T operator[](int k)const{return T(C[k].real());}
};
template<std::uint_fast64_t p=100000>
class MultiInt{
  private:
    std::vector<long long> _num;
    constexpr void shift(std::vector<long long> &a)const{
        size_t k=0;
        for(;k+1<a.size();++k){
            if(a[k]>=0){
                a[k+1] += a[k]/p;
                a[k] %= p;
            }
            else{
                long long n=(-a[k]+p-1)/p;
                a[k] += p*n;
                a[k+1] -= n;
            }
        }
        while(a[k]<=-(long long)p){
            long long n=(-a[k]+p-1)/p;
            a[k++] += p*n;
            a.push_back(-n);
        }
        while(a[k]>=(long long)p){
            a.push_back(0);
            a[k+1] += a[k]/p;
            a[k++] %= p;
        }
        while(a.back()==0) a.pop_back();
        if(a.empty()) a.push_back(0);
    }
    struct Decimal{
        MultiInt x;
        size_t k;
        Decimal cut(size_t t){if(t==x._num.size()) x=MultiInt(0);else x>>=t;k-=t;return *this;}
        Decimal(){}
        Decimal(const MultiInt &xt,const size_t &kt):x(xt),k(kt){}
        Decimal operator+(const Decimal &y)const{
            if(k<=y.k){
                MultiInt z=x;
                z<<=y.k-k;
                z+=y.x;
                return Decimal(z,y.k);
            }
            else{
                MultiInt z=y.x;
                z<<=k-y.k;
                z+=x;
                return Decimal(z,k);
            }
        }
        Decimal operator-(const Decimal &y)const{
            if(k<=y.k){
                MultiInt z=x;
                z<<=y.k-k;
                z-=y.x;
                return Decimal(z,y.k);
            }
            else{
                MultiInt z=y.x;
                z<<=k-y.k;
                z-=x;
                return Decimal(z,k);
            }
        }
        Decimal operator*(const Decimal &y)const{
            return Decimal(x*y.x,k+y.k);
        }
        Decimal operator+(const MultiInt &y)const{
            MultiInt z=y;z<<=k;z+=x;
            return Decimal(z,k);
        }
        Decimal operator-(const MultiInt &y)const{
            MultiInt z=y;z<<k;z-=x;
            return Decimal(z,k);
        }
        Decimal operator*(const MultiInt &y)const{
            return Decimal(x*y,k);
        }
        Decimal operator+=(const Decimal &y){*this = *this + y;return *this;}
        Decimal operator-=(const Decimal &y){*this = *this - y;return *this;}
        Decimal operator*=(const Decimal &y){x*=y.x;k+=y.k;return *this;}
        Decimal operator+=(const MultiInt &y){*this = *this + y;return *this;}
        Decimal operator-=(const MultiInt &y){*this = *this - y;return *this;}
        Decimal operator*=(const MultiInt &y){x*=y;return *this;}
    };
  public:
    constexpr size_t size()const{return _num.size();};
    constexpr int operator[](int k)const{return _num[k];}
    explicit constexpr MultiInt(long long num=0){
        while(num){
            _num.push_back(num%p);
            num /= p;
        }
        if(_num.empty()) _num.push_back(0);
    }
    explicit constexpr MultiInt(std::vector<long long> num):_num(num){shift(_num);}
    constexpr MultiInt(const MultiInt &cp):_num(cp._num){}
    constexpr MultiInt operator+(const MultiInt &x)const{
        size_t sz = std::max(_num.size(),x._num.size());
        std::vector<long long> c(sz);
        for(size_t i=0;i<sz;++i){
            if(i<_num.size()) c[i] += _num[i];
            if(i<x._num.size()) c[i] += x._num[i];
        }
        return MultiInt(c);
    }
    constexpr MultiInt operator-(const MultiInt &x)const{
        size_t sz = std::max(_num.size(),x._num.size());
        std::vector<long long> c(sz);
        for(size_t i=0;i<sz;++i){
            if(i<_num.size()) c[i] += _num[i];
            if(i<x._num.size()) c[i] -= x._num[i];
        }
        return MultiInt(c);
    }
    constexpr MultiInt operator-(void)const{
        return MultiInt(0)-*this;
    }
    constexpr MultiInt operator*(const MultiInt &x)const{
        size_t N = _num.size(),M = x._num.size();
        size_t i=0,k=0;
        if(N>=M){
            std::vector<long long> res(N+3*M),L(M);
            while(i<N){
                size_t D=i;
                for(;i-D<M;++i){
                    if(i<N) L[i-D]=_num[i];
                    else L[i-D]=0;
                }
                FFT<long long> r(L,x._num);
                for(size_t j=0;j<2*M-1;++j) res[j+k*M] += r[j];
                ++k;
            }
            return MultiInt(res);
        }
        else{
            std::vector<long long> res(M+3*N),R(N);
            while(i<M){
                size_t D=i;
                for(;i-D<N;++i){
                    if(i<M) R[i-D]=x._num[i];
                    else R[i-D]=0;
                }
                FFT<long long> r(_num,R);
                for(size_t j=0;j<2*N-1;++j) res[j+k*N] += r[j];
                ++k;
            }
            return MultiInt(res);
        }
    }
    constexpr MultiInt operator/(const MultiInt &x)const{
        Decimal res(MultiInt(1),x._num.size());
        Decimal dres=res;
        while(1){
            dres=res*(Decimal(MultiInt(2),0)-res*x);
            bool ok=true;
            if(res.k<_num.size()){
                res=dres;
                continue;
            }
            size_t szx=res.x._num.size(),szd=dres.x._num.size();
            for(size_t i=1;i<=szx-res.k+_num.size()+1;++i) if(res.x._num[szx-i]!=dres.x._num[szd-i]){
                res=dres;
                ok=false;
                break;
            }
            if(ok) break;
            if(res.k>3*x._num.size()) res.cut(res.k-3*x._num.size());
        }
        res.cut(res.k-_num.size()-1);
        res*=(*this);
        res.cut(res.k);
        while((res.x+1)*x<*this){
            res.x+=1;
        }
        return res.x;
    }
    constexpr MultiInt operator%(const MultiInt &x)const{
        return *this - *this/x;
    }
    constexpr MultiInt operator+(const long long t)const{
        std::vector<long long> res=_num;
        res[0]+=t;
        if(res[0]>=(long long)p) shift(res);
        return MultiInt(res);
    }
    constexpr MultiInt operator-(const long long &t)const{
        std::vector<long long> res = _num;
        res[0]-=t;
        if(res[0]<0) shift(res);
        return MultiInt(res);
    }
    constexpr MultiInt operator*(const long long &t)const{
        std::vector<long long> res=_num;
        for(size_t i=0;i<res.size();++i) res[i]*=t;
        shift(res);
        return MultiInt(res);
    }
    constexpr MultiInt operator/(const long long &t)const{
        return *this/MultiInt(t);
    }
    constexpr bool operator<(const MultiInt &x)const{
        if(_num.back()<0&&x._num.back()<0){
            if(_num.size()!=x._num.size()) return _num.size() > x._num.size();
            else for(size_t i=_num.size()-1;i>=0;--i){
                if(_num[i]!=x._num[i]) return _num[i] < x._num[i];
            }
        }
        else if(_num.back()*x._num.back()<0) return _num.back() < 0;
        else{
            if(_num.size()!=x._num.size()) return _num.size() < x._num.size();
            else for(size_t i=_num.size()-1;i>=0;--i){
                if(_num[i]!=x._num[i]) return _num[i] < x._num[i];
            }
        }
        return false;
    }
    constexpr bool operator==(const MultiInt &x)const{return _num==x._num;}
    constexpr bool operator!=(const MultiInt &x)const{return _num!=x._num;}
    constexpr bool operator>(const MultiInt &x)const{return !(*this==x||*this<x);}

    constexpr MultiInt operator<<(size_t k)const{
        std::vector<long long> res(_num.size()+k);
        for(size_t i=k;i<_num.size()+k;++i) res[i]=_num[i-k];
        return MultiInt(res);
    }
    constexpr MultiInt operator>>(size_t k)const{
        if(_num.size()<k){
            std::cerr<<"MultiInt operator>> overshifted"<<std::endl;
            exit(1);
        }
        std::vector<long long> res(_num.size()-k);
        for(size_t i=0;i+k<_num.size();++i) res[i]=_num[i+k];
        return MultiInt(res);
    }

    constexpr MultiInt operator+=(const MultiInt &x){
        size_t sz = std::max(_num.size(),x._num.size());
        if(_num.size()<sz) _num.resize(sz);
        for(size_t i=0;i<x._num.size();++i) _num[i]+=x._num[i];
        shift(_num);
        return *this;
    }
    constexpr MultiInt operator-=(const MultiInt &x){
        size_t sz = std::max(_num.size(),x._num.size());
        if(_num.size()<sz) _num.resize(sz);
        for(size_t i=0;i<x._num.size();++i) _num[i]-=x._num[i];
        shift(_num);
        return *this;
    }
    constexpr MultiInt operator*=(const MultiInt &x){*this = *this * x;return *this;}
    constexpr MultiInt operator/=(const MultiInt &x){*this = *this / x;return *this;}
    constexpr MultiInt operator%=(const MultiInt &x){return *this = *this %x;return *this;}

    constexpr MultiInt operator+=(const long long &a){_num[0]+=a;if(_num[0]>=(long long)p){shift(_num);}return *this;}
    constexpr MultiInt operator-=(const long long &a){_num[0]-=a;if(_num[0]<0){shift(_num);}return *this;}
    constexpr MultiInt operator*=(const long long &a){
        for(size_t i=0;i<_num.size();++i) _num[i]*=a;
        shift(_num);
        return *this;
    }
    constexpr MultiInt operator/=(const long long &a){*this/=MultiInt(a);return *this;}
    constexpr MultiInt operator<<=(size_t k){
        _num.resize(_num.size()+k);
        for(int i=_num.size()-1-k;i>=0;--i){
            _num[i+k]=_num[i];
            _num[i]=0;
        }
        return *this;
    }
    constexpr MultiInt operator>>=(size_t k){
        if(_num.size()<k){
            std::cerr<<"MultiInt operator>>= overshifted"<<std::endl;
            exit(1);
        }
        for(size_t i=0;i+k<_num.size();++i) _num[i]=_num[i+k];
        while(k--) _num.pop_back();
        return *this;
    }
    
    friend constexpr std::ostream& operator<<(std::ostream &os,const MultiInt &x){
        size_t i=x.size();
        if(x._num.back()>=0){
            os<<x[--i];
            while(i--) printf("%05d",x[i]);
        }
        else os<<'-'<<MultiInt(-x);
        return os;
    }
    friend std::istream& operator>>(std::istream &is,MultiInt &x){
        long long val;is>>val;
        x._num.clear();
        while(val){x._num.push_back(val%p);val/=p;}
        return is;
    }
};


int main(){
    using namespace std;
    using MI =MultiInt<100000>;
    MI N,M;
    cin>>N>>M;
    if(N==M) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
