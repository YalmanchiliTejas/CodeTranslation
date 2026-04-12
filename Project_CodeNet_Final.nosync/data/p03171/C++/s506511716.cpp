//SHIVANSH BHAT
//IIT ROORKEE

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long int ll;
typedef unsigned long long int ull;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
ll mod1=pow(10,9)+7;
int mod2=998244353;
ll inf=1e9;
ll maxxy=1e6+9;
typedef long double ld;
const double PI =  3.141592653589793238;

//NUMBER THEORY
//(a-b)%c=((a%c)-((b%c))+c)%c;
//to find gcd use function __gcd(x,y);

//Seive of erathonesis(finding prime numbers till n)
/*
 *
 *
************************************************************************
       vector<bool> isPrime(n+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
*************************************************************************

*/
//Prime Factorisation of numbers of large orders like 1e9,1e12 in O(sqrt(N))
/*
 *
 **********************************************************************
 vector<ll> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
 ***********************************************************************

 */
//Prime Factors of numbers of order 1e5,1e6 in O(logn) using seive
/*
 *
 ***********************************************************************
 //max_value is upper limit of elements we have to factorise
 vector<ll> minPrime(max_value + 1,0);
for (int i = 2; i * i <= max_value; ++i) {
    if (minPrime[i] == 0) {         //If i is prime
        for (int j = i * i; j <= max_value; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= max_value; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}
//factorising array of elements in log(n)
 for(int i=0;i<n;i++){
     vector<ll> res;
    while (a[i] != 1) {
        res.push_back(minPrime[a[i]]);
        a[i] /= minPrime[a[i]];
    }
 }
 ****************************************************************

 */

//to get sum of b consecutive non negative integers starting from a
ull sumcons(ull a,ull b){
    if(a==0){
        return (b*(b-1))/2;
    }
    else{
        ull zzz=(b*(b+1))/2;
        zzz+=((a-1)*b);
        return zzz;
    }
}
ll power(ll x, ll y, ll pp)
{
    ll res = 1;
    x = x % pp;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % pp;
        y = y>>1;
        x = (x*x) % pp;
    }
    return res;
}

ll modInverse(ll n, ll pp)
{
    return power(n, pp-2, pp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
        sum+=a[i];
    }
    ll dp[n][n];
    for (int size = 1; size <=n ; ++size) {
        for (int i = 0; i <n-size+1 ; ++i) {
             ll j=i+size-1;
             ll left=n-size;
              if(left%2==0){
                  if(i==j)
                      dp[i][j]=a[i];
                  else
                      dp[i][j]=max(dp[i][j-1]+a[j],dp[i+1][j]+a[i]);
              }
              else{
                  if(i==j)
                      dp[i][j]=0;
                  else
                      dp[i][j]=min(dp[i][j-1],dp[i+1][j]);
              }
        }
    }
    //cout<<dp[0][n-1]<<"\n";
    cout<<2*dp[0][n-1]-sum<<"\n";
    return 0;
}
