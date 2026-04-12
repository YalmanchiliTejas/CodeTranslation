#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Y cout << "Yes\n"
#define N cout << "No\n"
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define R(i, n) for (int i = 0; i < n; i++)
#define RE(i, a, b) for (int i = a; i >= b; i--)

long long mod = 1000000007 , ans = 1 ;
int p(long long a , long long b)
{
    while(b)
    {
        if(b%2)
        {
            ans = ( (ans%mod)*(a%mod) ) %mod ;
        }
        a = ((a%mod)*(a%mod))%mod ;
        b /= 2 ;
    }
    return ans ;
}


int prime[1000010] ;
void fun()
{
	for (int i = 2; i < 1000001; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i + i; j < 1000001; j += i)
			{
				prime[j] = 1;
			}
		}
	}
}
int gcd(ll a,ll b)
{
     if(b == 0)
     {
          return a ;
     }
     return gcd(b,a%b) ;
}
int main()
{
     // ios_base::sync_with_stdio(false);
     // cin.tie(NULL);
     ll n , arr[200010] ;
     cin >> n ;
     R(i,n)
     {
          int x ;
          cin >> x ;
          if(i == 0)
          {
               arr[i] = x ;
          }
          else
          {
               arr[i] = x + arr[i-1] ;
          }
     }
     ans = 0 ;
     R(i,n-1)
     {
          ll x = arr[n-1]-arr[i] ;
          ll z ;
          if(i == 0)
          {
               z = ( (x%mod)*(arr[0]%mod) )%mod ;
          }
          else
          {
               z = ( (x%mod)*((arr[i]-arr[i-1])%mod) )%mod ;
          }
          ans = ( (ans%mod) + (z%mod) )%mod ;
     }
     cout << ans << endl ;
}
