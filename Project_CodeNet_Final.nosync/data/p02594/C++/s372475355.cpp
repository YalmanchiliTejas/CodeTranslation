#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const long long MOD = 1e9+7;

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

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

int main()
{
    ll X;
    cin >> X;

    if(X>=30) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}