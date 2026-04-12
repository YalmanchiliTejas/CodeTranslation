#include <iostream>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>
#include <string.h>
#include <string>
#include <algorithm>
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define inf 1e18
#define mem(a,b) memset(a,b,sizeof(a))
#define debug(x) cout << (#x) << " = " << x << endl;
#define debug2(i,j) cout << (#i) << "=" << i << " , " << (#j) << "=" << j << endl;

using namespace std;

ll binomialCoeff(ll n,ll k)
{
    ll res = 1;
    if(k >n - k)
        k = n - k;
    for(int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll power(ll x,ll y)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}


// // nCr % mod
// const int Nf = 1e5 + 5;
// ll fact[6*Nf];
// ll inv[6*Nf],invfac[6*Nf];
// //ll mod = 1e9 + 7;

// void factorial()
// {
//     fact[0] = invfac[0] = fact[1] = invfac[1] = 1;
//     inv[1] = 1;
//     for(int i=2;i<=5*Nf + 10;i++)
//     {
//         fact[i] = (fact[i-1]*i)%mod;
//         inv[i] = (inv[mod%i]*(mod - mod/i))%mod;
//         invfac[i] = (invfac[i-1]*inv[i])%mod;
//     }
// }

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

vector<ll> primes;
vector<bool> prime;

void Sieve(int n)
{
    prime = vector<bool> (n+1,true);
    //vector<bool> prime(n+1,true);
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          primes.push_back(p);
}

//******************************************************    CHECK CONSTRAINTS   ***************************************************************//

const int Nmax = 1e5 + 6;
const int N = 1005;

ll dp[Nmax][105][2];

ll mod = 1e9 + 7;

string str;
int d;
int n;

ll solve(int pos,int rem,int f)
{
    if(pos == n)
    {
        if(rem%d == 0)
        {
            return 1;
        }
        return 0;
    }

    ll &res = dp[pos][rem][f];
    if(~res)
        return res;

    int limit;
    res = 0;

    if(f == 0)
    {
        limit = str[pos] - '0';
    }
    else
        limit = 9;

    for(int i=0;i<=limit;i++)
    {
        int nf = f;
        int div = rem;
        if(f == 0 && i < limit)
            nf= 1;
        div = (rem+i)%d;
        res += solve(pos+1,div,nf);
        res %= mod;
    }
    //cout << pos << " " << rem <<  " " << res << "\n";
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> str;
    cin >> d;
    n = str.length();
    //reverse(str.begin(),str.end());
    mem(dp,-1);
    cout << (solve(0,0,0) - 1 + mod)%mod;
}
