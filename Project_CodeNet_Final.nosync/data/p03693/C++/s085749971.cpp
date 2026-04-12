#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define INF 999999999
#define rep(i, n) for(int i = 0;i < n;i++)
#define pb(n) push_back(n)
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define Vecpr vector<pair<lli,lli>>
int main() {
  lli A,B,C,D;
  string a,b,c;
  cin >>A>>B>>C;
  A=100*A+10*B+C;
  if(A%4==0)Out("YES");
  else Out("NO");
}
