#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const long long MOD = 1e9+7;

const long long INF = 1e15;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

void ALLOUT_NUMBER(vector<ll> V)
{
    ll N = V.size();
    for(ll i=0;i<N;i++)
    {
        cout << V[i];
        if(i<N-1) cout << ' ';
    }
    cout << endl;
}


class Mll
{
    public:
    ll x;

    Mll() : x(0){}
    Mll(ll x=0) : x((x%MOD+MOD)%MOD){}

    Mll operator-() const
    {
        return Mll(-x);
    }

    Mll& operator+=(const Mll& A)
    {
        if((x += A.x) >= MOD) x -= MOD;
        return *this;
    }
    Mll& operator-=(const Mll& A)
    {
        if((x += MOD - A.x) >= MOD) x -= MOD;
        return *this;
    }
    Mll& operator*=(const Mll& A)
    {
        (x *= A.x) %= MOD;
        return *this;
    }
    
    Mll operator+(const Mll& A)
    {
        Mll res(*this);
        return res+=A;
    }
    Mll operator-(const Mll& A)
    {
        Mll res(*this);
        return res-=A;
    }
    Mll operator*(const Mll& A)
    {
        Mll res(*this);
        return res*=A;
    }
    
    Mll pow(ll t) const // t乗
    {
        if(t==0) return 1;
        Mll A = pow(t>>1);
        A *= A;
        if(t&1) A *= *this;
        return A;
    }

    // for prime mod
    Mll inv() const
    {
        return pow(MOD-2);
    }
    Mll& operator/=(const Mll& A)
    {
        return (*this) *= A.inv();
    }
    Mll operator/(const Mll& A) const
    {
        Mll res(*this);
        return res/=A;
    }

    friend ostream& operator<<(ostream& os, const Mll& M)
    {
        os << M.x;
        return os;
    }
};

vector<Mll> ALLIN_MLL(ll N)
{
    vector<ll> numbers_ll(N);
    ALLIN1_NUMBER(numbers_ll);

    vector<Mll> numbers_Mll;
    for(ll i=0;i<N;i++)
    {
        Mll add(numbers_ll[i]);
        numbers_Mll.push_back(add);
    }

    return numbers_Mll;
}

ll ceil(ll dividend, ll divisor)
{
    return (dividend + divisor - 1) / divisor;
}

class UnionFind
{
    public:
    vector<ll> par;

    UnionFind(ll n) : par(n)
    {
        for(ll i=0;i<n;i++)
        {
            par[i]=i;
        }
    }

    ll root(ll i)
    {
        if(par[i]==i) return i;
        return par[i] = root(par[i]);
    }

    bool Is_root(ll i)
    {
        return i == root(i);
    }

    void unite(ll a, ll b)
    {
        ll ra = root(a), rb = root(b);
        if(ra==rb) return;
        par[ra] = par[rb];
        return;
    }

    bool same(ll a, ll b)
    {
        return root(a) == root(b);
    }

    ll groups_num(const UnionFind& U)
    {
        ll N = U.par.size();
        ll counter = 0;
        for(ll i=0;i<N;i++)
        {
            if(Is_root(i)) counter++;
        }
        return counter;
    }
};


static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

vector<ll> RUI_up(vector<ll> A, ll N)
{
    vector<ll> ret(N);
    ret[0]=0;
    for(ll i=1;i<N;i++)
    {
        if(A[i]>A[i-1]) ret[i] = ret[i-1]+1;
        else ret[i] = ret[i-1];
    }
    return ret;
}

// N個のNodeに対して、(N以上の最大の2冪の数)*2-1要素の配列を用意する。
class Seg_Tree
{
    public:
    ll n;
    vector<ll> V;
    
    Seg_Tree(ll N) : n(N)
    {
        ll nz = 1;
        while(nz<N) nz*=2;
        V.resize(nz*2-1,-1);
        for(ll i=nz-1;i<nz+N-1;i++)
        {
            cin >> V[i];
        }
        for(ll i=nz-2;i>=0;i--)
        {
            V[i] = compare(V[i*2+1],V[i*2+2]);
        }
    }

    ll compare(ll A, ll B)
    {
        if(A==-1 && B==-1) return -1;
        else if(A==-1) return B;
        else if(B==-1) return A;
        else return min(A,B);
    }

    void update(ll m, ll num)
    {
        ll nz = 1;
        while(nz<n) nz*=2;
        
        m += nz;
        V[m] = num;
        while(m>0)
        {
            m = (m-1)/2;
            V[m] = compare(V[m*2+1],V[m*2+2]);
        }
    }

    // [A, B)
    ll Get(ll A, ll B, ll k=0, ll l=0, ll r=-1)
    {
        if(r<0) r = n;
        //if(r<=A || B<=l)
    }
};

map<ll,ll> Divs_only_prime(ll N)
{
    map<ll,ll> ret;
    ll N_copy = N;
    for(ll i=2;i*i<=N;i++)
    {
        while(N_copy%i==0)
        {
            ret[i]++;
            N_copy /= i;
        }
    }
    if(N_copy!=1) ret[N_copy]++;
    return ret;
}

int main()
{
    ll N;
    cin >> N;

    vector<Mll> A(N,Mll(0));
    for(auto& x : A)
    {
        ll add;
        cin >> add;
        x=Mll(add);
    }

    Mll ans(0);
    for(auto x : A)
    {
        ans+=x;
    }

    ans*=ans;

    for(auto x : A)
    {
        ans -= x*x;
    }

    ans/=Mll(2);

    cout << ans.x << endl;

    return 0;
}