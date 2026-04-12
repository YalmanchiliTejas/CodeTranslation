#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll lay[55],pat[55];

ll func(int n, ll x)
{
  if(n==0) return (x<=0 ? 0 : 1);
  else if(x<=lay[n-1]+1) return func(n-1,x-1);
  else return pat[n-1] + 1 + func(n-1,x-2-lay[n-1]);
  
}
  
int main()
{
  int n;
  ll x;
  cin >> n >> x;
  lay[0]=1;
  pat[0]=1;
  FOR(i,1,n){
    lay[i] = 2*lay[i-1]+3;
    pat[i] = 2*pat[i-1]+1;
  }
  cout << func(n,x) << '\n';

}
