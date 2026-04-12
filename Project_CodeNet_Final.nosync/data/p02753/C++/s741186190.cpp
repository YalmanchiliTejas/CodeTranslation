/* *****fireice**** */

#include<bits/stdc++.h>

#define ll long long int
#define ld long double
#define vi vector<int>
#define vc vector<char>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define el '\n'
#define N 1000000007
#define re return
#define F first
#define S second
#define L length
#define mp make_pair
#define PI 3.14159265
#define all(a) (a).begin(),(a).end()
#define forup(i,n) for(int i=0;i<n;i++)
#define forf(i,x,n) for(int i=x;i<n;i++)
#define ford(i,n) for(int (i)=(n)-1;i>=0;(i)--)
#define take(a,n) forup(i,n) cin>>a[i];
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
        // m is added to handle negative x
    ll res = ((ll)x%m + (ll)m) % m;

    return res;
}

ll poww(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n==1) return x;
    else if(n%2 == 0)        //n is even
        return poww(x*x,n/2);
    else                              //n is odd
        return x*poww(x*x,(n-1)/2);
}

ll modularExponentiation(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

template<typename T>
T maxx(T a,T b)
{
  if(a<b) re b;
  re b;
}
template<typename T, typename... Args>
T maxx(T a,T b, Args... args)
{
    re(maxx(maxx(a,b),args...));
}

template<typename T>
T minn(T a,T b)
{
  if(a<b) re a;
  re b;
}
template<typename T, typename... Args>
T minn(T a,T b, Args... args)
{
    re(minn(minn(a,b),args...));
}

inline ll min(ll a,ll b)
{
  if(a<b) re a;
  else re b;
}
inline ll max(ll a,ll b)
{
  if(a<b) re b;
  else re a;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);
    else return gcd(a, b-a);
}

ll ncr(int n,int r)
{
  ll ans=1;
  r=min(r,n-r);
  forup(i,r)
  {
    ans=(ans*(n-i)/(i+1))%N;
  }
  re ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  //cin>>t;
  while(t--)
  {
    ll n,m,k;
    string s;
    cin>>s;
    if(s=="AAA" || s=="BBB") cout<<"No";
    else cout<<"Yes";

  }


  return 0;
}
