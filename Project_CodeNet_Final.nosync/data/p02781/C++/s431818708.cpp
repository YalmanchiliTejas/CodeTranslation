// Garg's Code
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define ll long long
#define vec vector < ll >
#define pb push_back
#define po pop_back
#define mp make_pair
#define mt make_tuple
#define F  first
#define S  second
#define f(i,x,n) for(ll i=x;i<n;i++)
#define rf(i,x,n) for(ll i = x; i >= x; i--)
#define all(c) c.begin(),c.end()
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
const ll MAX = LLONG_MAX, MOD = 1000000007, MODA = 1e9 - 1;
const ll MIN = LLONG_MIN;
const long double PI = 3.1415926535;
const ll N = 100009;

int main()
{
  fast();

  ll t=1;
  //cin >> t;
  while(t--)
  {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n = s.length();
    string abc = "";
    f(i,0,n)
    {
      abc += '0';
    }
    ll ans = 0;
    if(k == 1)
    {
      f(i,0,n)
      {
        if(i == 0)
          ans += s[i] - '0';
        else
          ans += 9;
      }
    }
    if(k == 2)
    {
      if(n<2)
      {
        cout << 0;
        return 0;
      }
      f(i,0,n-1)
      {
        if(i == 0)
        {
          ans += (s[i]-'1')*(9*((n-1)-i));
          abc[0] = s[0];
          f(j,1,n)
          {
            f(k,1,10)
            {
              abc[j] = k + '0';
              if(abc <= s)
              {
                //cout << abc << endl;
                ans++;
              }
            }
            abc[j] = '0';
          }
        }
        else
        {
          ans += (9)*(9*((n-1)-i));
        }
      }
    }
    if(k==3)
    {
      if(n < 3)
      {
        cout << 0;
        return 0;
      }
      f(i,0,n-2)
      {
        if(i == 0)
        {
          ans += (s[i]-'1')*(81)*(((n-1-i)*(n-2-i))/2);
          abc[0] = s[0];
          f(j,1,n-1)
          {
            f(k,1,10)
            {
                abc[j] = k + '0';
                f(l,j+1,n)
                {
                  f(m,1,10)
                  {
                    abc[l] = m + '0';
                  if(abc <= s)
                    ans++;
                  }
                  abc[l] = '0';
                }
                
            }
            abc[j] = '0';
          }
        }  
        else
        {
          ans += (9)*(81)*(((n-1-i)*(n-i-2))/2);
        }
      }
    }
    cout << ans ;
  }
  return 0;
}
