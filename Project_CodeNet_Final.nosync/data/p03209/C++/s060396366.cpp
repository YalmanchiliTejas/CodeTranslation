#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;
int MAXI = 1e8 + 1;
using vec = vector<int>;

ll
rec(int n, ll x)
{
  if(n == 0) return 1;
  ll half = pow(2, n + 1) - 3;
  ll phalf = pow(2, n) - 1;
  if(x == 1) return 0;
  else if(x <= 1 + half) return rec(n - 1, x - 1);
  else if(x == 1 + half + 1) return phalf + 1;
  else if(x <= 1 + half + 1 + half) return phalf + 1 + rec(n - 1, x - 2 - half);
  else return (2 * phalf) + 1;

}

int 
main()
{
  int N; cin >> N;
  ll X; cin >> X;
  cout << rec(N, X) << endl;

}