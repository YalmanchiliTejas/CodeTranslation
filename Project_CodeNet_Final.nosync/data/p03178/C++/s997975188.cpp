#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(n) ((int)(n).size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

ll MOD=1e9+7, d, dp[10010][100][2];
string s;

ll solve(int pos, int m, bool low){
  if(pos == SZ(s)) return m==0;
  ll &r = dp[pos][m][low];
  if(r >= 0) return r;
  r = 0;
  ll top = low?10:(s[pos]-'0'+1), exp = SZ(s)-pos-1;
  fore(i,0,top) r = (r + solve(pos+1, (m+i)%d, low||i<(s[pos]-'0')))%MOD;
  return r;
}


int main(){FIN;
  memset(dp,-1,sizeof(dp));
  cin >> s >> d;
  cout << (solve(0,0,0)-1+MOD)%MOD << endl;
}