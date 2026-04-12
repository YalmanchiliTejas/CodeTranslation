#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

//-------------------------------------------------
//--ModInt
//-------------------------------------------------
const ::std::uint_fast64_t MOD = 1e9+7;

class mint
{
private:
    using value_type = ::std::uint_fast64_t;
    value_type n;
public:
    mint():n(0){}
    mint(::std::int_fast64_t _n):n(_n<0 ? MOD-(-_n)%MOD : _n%MOD){}
    mint(const mint &m):n(m.n){}

    friend ::std::ostream& operator<<(::std::ostream &os, const mint &a){
		return os << a.n;
	}
    friend ::std::istream& operator>>(::std::istream &is, mint &a){
        value_type temp; is>>temp;
        a = mint(temp);
        return is;
    }

    mint& operator+=(const mint &m){n+=m.n; n=(n<MOD)?n:n-MOD; return *this;}
    mint& operator-=(const mint &m){n+=MOD-m.n; n=(n<MOD)?n:n-MOD; return *this;}
    mint& operator*=(const mint &m){n=n*m.n%MOD; return *this;}
    mint& operator/=(const mint &m){return *this*=m.inv();}
    mint& operator++(){return *this+=1;}
    mint& operator--(){return *this-=1;}

    mint operator+(const mint &m) const {return mint(*this)+=m;}
    mint operator-(const mint &m) const {return mint(*this)-=m;}
    mint operator*(const mint &m) const {return mint(*this)*=m;}
    mint operator/(const mint &m) const {return mint(*this)/=m;}
    mint operator++(int){mint t(*this); *this+=1; return t;}
    mint operator--(int){mint t(*this); *this-=1; return t;}

    mint operator==(const mint &m) const {return n==m.n;}
    mint operator!=(const mint &m) const {return n!=m.n;}
    mint operator-() const {return mint(MOD-n);}

    mint pow(value_type b) const {
        mint ret(1), m(*this);
        while(b){
            if (b & 1) ret*=m;
            m*=m;
            b>>=1;
        }
        return ret;
    }

    mint inv() const {return pow(MOD-2);}
};

//-------------------------------------------------
//--Combination (depends on ModInt)
//-------------------------------------------------
class Combination
{
private:
    ::std::vector<mint> _fact;
    ::std::vector<mint> _finv;
public:
    Combination(int n):_fact(n+1), _finv(n+1){
        _fact[0] = _fact[1] = 1;
        _finv[0] = _finv[1] = 1;
        for(int i=2; i<=n; i++){
            _fact[i] = _fact[i-1]*i;
            _finv[i] = _fact[i].inv();
        }
    }
    mint fact(int x){return _fact[x];}
    mint finv(int x){return _finv[x];}
    mint comb(int x, int y){
        if (y>x || y<0) return 0;
        return _fact[x]*_finv[y]*_finv[x-y];
    }
    mint homo(int x, int y){return comb(x+y-1, y);}
};

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k; cin>>n>>m>>k;
    Combination bn(n*m);
    mint ans=0;
    for(int i=1; i<=n-1; i++){
        ans += bn.comb(m*n-2,k-2)*i*(n-i)*m*m;
    }
    for(int i=1; i<=m-1; i++){
        ans += bn.comb(m*n-2,k-2)*i*(m-i)*n*n;
    }
    cout<<ans<<endl;
    return 0;
}
