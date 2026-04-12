#include "bits/stdc++.h"
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mFOR(i, a, b) for (int i = a; i > b; i--)
#define MP make_pair
#define PB push_back
#define ALL(v) v.begin(), v.end()
#define N 100007
#define INF 1000000007
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll fceil(ll a, ll b) { return (a % b == 0 ? a / b : a / b + 1); }
int main()
{
   int h, w;
   char a[100][100];
   bool x[100] = {}, y[100] = {};
   cin >> h >> w;
   FOR(i, 0, h)
   FOR(j, 0, w)
   {
      cin >> a[i][j];
   }

   FOR(i, 0, h)
   FOR(j, 0, w)
   {
      if (a[i][j] == '#')
      {
         x[i] = true;
         y[j] = true;
      }
   }

   FOR(i, 0, h)
   {
      if (x[i])
      {
         FOR(j, 0, w)
         {
            if (y[j])
               cout << a[i][j];
         }
         cout << endl;
      }
   }
   return 0;
}
