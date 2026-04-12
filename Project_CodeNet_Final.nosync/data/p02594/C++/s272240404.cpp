#include<bits/stdc++.h>
#define int long long

using namespace std;

#define forn(i, a, b) for(int i = a; i <= b; i++)

const double EPS = 1e-9;
const double pi = acos( -1. );
const int mod = 1e9 + 7;
int MAX = -1e18;
int MIN = 1e18;

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))

int mul_mod(int a, int b, int mod)
{
    int res = 0;
    while( b )
    {
        if( b & 1 )
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

int binpow(int a, int b, int mod)
{
    if(b==0) return 1;
    if(b%2==1) return mul_mod(a,binpow(a,b-1,mod),mod);
    else
    {
        int d=binpow(a, b/2, mod)%mod;
        return 1ll * mul_mod(d, d, mod) % mod;
    }
}

inline int GCD_E ( int a, int b, int & x, int & y )
{
    if ( !a )
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = GCD_E ( b % a, a, x1, y1 );
    x = y1 - ( b / a ) * x1;
    y = x1;
    return d;
}


inline int divMOD ( int a, int b, int m = mod)
{
    int x, y;
    int g = GCD_E ( b, m, x, y );
    x = ( x % m + m ) % m;
    return ( a * x ) % m;
}

bool is_prime( int n )
{
    int d = n - 1;
    int s = 0;
    while(d % 2 == 0)
    {
        s++;
        d >>= 1;
    }
    int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23};
    forn ( i, 0, 8 )
    {
        bool comp = ( binpow(a[i], d, n) != 1);
        if( comp )
            forn( j, 0, s-1 )
        {
            int fp = binpow(a[i], (1ll << j) * d, n);
            if(fp == n-1)
            {
                comp = false;
                break;
            }
        }
        if( comp ) return false;
    }
    return true;
}

bool isprime(int n)
{
    if(n<2) return false;
    for(int i=2; i*i*i<=n; ++i) if(n%i==0) return false;
    for(int it=0; it<1e5; ++it)
    {
        int i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        if(binpow(i,n-1,n)!=1) return false;
    }
    return true;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
int phi(int n)
{
    int result = n;

    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;
    return result;
}
main()
{
  int x;
  cin >> x;
  if(x >= 30){
    cout << "Yes";
  }
  else cout << "No";
}
