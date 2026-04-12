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

int n, done[3010][3010];
ll dp[3010][3010], a[3010];

ll solve(int l, int r){
  if(l > r) return 0;
  ll &R = dp[l][r];
  if(done[l][r]) return R;
  done[l][r] = true;
  return R = max(a[l]-solve(l+1,r), a[r]-solve(l,r-1));
}

int main(){FIN;
  cin >> n;
  fore(i,0,n) cin >> a[i];
  cout << solve(0,n-1) << "\n";
}