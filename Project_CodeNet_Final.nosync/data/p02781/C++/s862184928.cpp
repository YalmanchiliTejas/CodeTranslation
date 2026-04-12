#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;

int comb(int n, int k)
{
  if(n<k || k<0) return 0;
  int table[n + 1][n + 1];
  for (int i = 0; i <= n; i++)
    table[i][0] = 1;
  for (int i = 1; i <= k; i++)
    table[i][i] = 1;

  for (int i = 2; i <= n; i++)
  {
    for (int j = 1; j < min(i, k + 1); j++)
    {
      table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
    }
  }
  return table[n][k];
}


string s;
int k,N;

int rec(int i, int d, bool smaller)
{
  if(i==N){
    if(d==0) return 1;
    else return 0;
  }
  if(d==0) return 1;
  if(smaller) return comb(N-i,d) * pow(9, d);
  else{
    if(s[i]=='0') return rec(i+1, d, false);
    int tmp1 = rec(i+1, d, true);
    int tmp2 = rec(i+1, d-1, true) * (s[i]-'1');
    int tmp3 = rec(i+1, d-1, false);
    return tmp1+tmp2+tmp3;
  }
  
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s >> k;
  N = s.size();
  cout << rec(0, k, false) << endl;
  return 0;
}