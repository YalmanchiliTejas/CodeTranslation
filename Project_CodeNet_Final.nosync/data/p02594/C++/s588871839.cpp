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
#define N 100005
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

ll mod = 1e9+7;

ll power(ll x,ll y)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return (((x*temp)%mod)*temp)%mod;
}


/* nCr % mod
ll fact[6*N];
ll inv[6*N],invfac[6*N];
ll mod = 998244353;

void factorial()
{
    fact[0] = invfac[0] = fact[1] = invfac[1] = 1;
    inv[1] = 1;
    for(int i=2;i<=5*N + 10;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        inv[i] = (inv[mod%i]*(mod - mod/i))%mod;
        invfac[i] = (invfac[i-1]*inv[i])%mod;
    }
}*/

vector<ll> primes;

void Sieve(int n)
{
    vector<bool> prime(n+1,true);
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

const int Nmax = 1e6 + 6;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x;
    cin >> x;
    if(x>=30)
        cout << "Yes";
    else 
        cout << "No";
}
