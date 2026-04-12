#include<bits/stdc++.h>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;
typedef pair<llint, llint> pll;
typedef vector<int> vi;
typedef vector<llint> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define ci cin
#define co cout
#define en endl
#define ln cout<< '\n'
#define rep(i, n) for(int i = 0; i < n; i++)
#define outl(x) cout<< (x) << '\n'
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

template<typename Tn> Tn gcd(Tn a, Tn b)
{
  return (b ? gcd(b, a % b) : a);
}

template<typename Tn> Tn lcm(Tn a, Tn b)
{
  return a / gcd(a, b) * b;
}

llint cnt = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
  int x;
  ci >> x;

  if(x == 3 || x == 5 || x == 7) co << "YES" << en;
  else co << "NO" << en;
  
  return 0;
}
