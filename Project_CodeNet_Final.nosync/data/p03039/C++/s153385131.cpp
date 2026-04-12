#include <iostream>

constexpr long long order_of_field = 1e9 + 7;

//element of Z/pZ
class Modulo
{
private:
    long long p;
    long long n;
public:
    Modulo(): p(order_of_field), n(1) {}
    Modulo(long long n0);
    
    bool operator==(const Modulo rhs) const{return n == rhs.n;}
    Modulo& operator+=(const long long rhs);
    Modulo& operator+=(const Modulo& rhs);
    Modulo& operator*=(const long long rhs);
    Modulo& operator*=(const Modulo& rhs);
    Modulo& operator-=(const long long rhs);
    Modulo& operator-=(const Modulo& rhs);
    Modulo pow(const long long k) const;
    Modulo inverse() const;
    Modulo& operator/=(const long long rhs);
    Modulo& operator/=(const Modulo& rhs);
    long long get() const{return n;};
};

const Modulo operator+(const Modulo &lhs, const Modulo &rhs);
const Modulo operator+(const Modulo &lhs, const long long rhs);
const Modulo operator+(const long long lhs, const Modulo &rhs);
const Modulo operator*(const Modulo &lhs, const Modulo &rhs);
const Modulo operator*(const Modulo &lhs, const long long rhs);
const Modulo operator*(const long long lhs, const Modulo &rhs);

//constructor
Modulo::Modulo(long long n0)
{
    p = order_of_field;
    n = n0 >= 0 ? n0 % p : (p - (-n0 % p)) % p;
}

//operator +=
inline Modulo& Modulo::operator+=(const long long rhs)
{
    long long rhs1 = rhs >= 0 ? rhs % p : (p - (-rhs % p)) % p;
    n = (n + rhs1) % p;
    return *this;
}

inline Modulo& Modulo::operator+=(const Modulo& rhs)
{
    (*this) += rhs.n;
    return *this;
}

//operator *=
inline Modulo& Modulo::operator*=(const long long rhs)
{
    long long rhs1 = rhs >= 0 ? rhs % p : (p - (-rhs % p)) % p;
    n = (n * rhs1) % p;
    return *this;
}

inline Modulo& Modulo::operator*=(const Modulo& rhs)
{
    (*this) *= rhs.n;
    return *this;
}

//operator -=
inline Modulo& Modulo::operator-=(const long long rhs)
{
    return *this += -rhs;
}

inline Modulo& Modulo::operator-=(const Modulo& rhs)
{
    (*this) -= rhs.get();
    return *this; 
}

//(*this)**k
Modulo Modulo::pow(const long long k) const
{
    if(k == 0) return 1;
    if(k == 1) return n;
    long long k1 = k >= 0 ? k % (p-1) : ((p-1) - (-k % (p-1))) % (p-1);
    Modulo r = pow(k1/2);
    if(k1 % 2 == 0) return r * r;
    else return r * r * n; 
}

//(*this)**(-1)
Modulo Modulo::inverse() const
{
    return pow(-1);
}

//operator /=
inline Modulo& Modulo::operator/=(const long long rhs)
{
    Modulo inv = rhs;
    inv = inv.inverse();
    return *this *= inv;
}

inline Modulo& Modulo::operator/=(const Modulo& rhs)
{
    (*this) /= rhs.get();
    return *this; 
}

//operator +
const Modulo operator+(const Modulo &lhs, const Modulo &rhs)
{
    return Modulo(lhs.get()) += rhs;
}

const Modulo operator+(const Modulo &lhs, const long long rhs)
{
    return Modulo(lhs.get()) += rhs;
}

const Modulo operator+(const long long lhs, const Modulo &rhs)
{
    return Modulo(lhs) += rhs;
}

//operator *
const Modulo operator*(const Modulo &lhs, const Modulo &rhs)
{
    return Modulo(lhs.get()) *= rhs;
}

const Modulo operator*(const Modulo &lhs, const long long rhs)
{
    return Modulo(lhs.get()) *= rhs;
}

const Modulo operator*(const long long lhs, const Modulo &rhs)
{
    return Modulo(lhs) *= rhs;
}

//operator -
const Modulo operator-(const Modulo &lhs, const Modulo &rhs)
{
    return Modulo(lhs.get()) -= rhs;
}

const Modulo operator-(const Modulo &lhs, const long long rhs)
{
    return Modulo(lhs.get()) -= rhs;
}

const Modulo operator-(const long long lhs, const Modulo &rhs)
{
    return Modulo(lhs) -= rhs;
}

//operator /
const Modulo operator/(const Modulo &lhs, const Modulo &rhs)
{
    return Modulo(lhs.get()) /= rhs;
}

const Modulo operator/(const Modulo &lhs, const long long rhs)
{
    return Modulo(lhs.get()) /= rhs;
}

const Modulo operator/(const long long lhs, const Modulo &rhs)
{
    return Modulo(lhs) /= rhs;
}

//very very useful functions
//n**k
Modulo pow(Modulo n, long long k)
{
    Modulo tmp = n;
    tmp = tmp.pow(k);
    return tmp;
}

//n!
void fact_set(long long *base, int size)
{
    Modulo m = 1;
    if(size >= 0) base[0] = 1;
    for(int i=1; i<size; i++){
        m *= i;
        base[i] = m.get();
    }
}

//nCk
Modulo comb(long long n, long long k, long long *fact)
{
    Modulo a = fact[n];
    Modulo b = fact[k];
    Modulo c = fact[n-k];
    return a / b / c;
}

int main()
{
    int N, M, K;
    std::cin >> N >> M >> K;

    long long fact[N*M+1];
    fact_set(fact, N*M+1);

    Modulo sum = 0;
    for(int i=1; i<N; i++) sum += Modulo(i) * (N-i) * M * M;
    for(int i=1; i<M; i++) sum += Modulo(i) * (M-i) * N * N;
    sum *= comb(N*M-2, K-2, fact);
    
    std::cout << sum.get() << std::endl;
}