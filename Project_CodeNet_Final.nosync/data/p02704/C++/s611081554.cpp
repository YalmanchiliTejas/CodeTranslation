#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 510;
int s[N], t[N];
ull u[N], v[N];
bool cu[N], vu[N];
ull ans[N][N];
int cur[N][N];
int n;

int ci[N], cj[N];

void setbit(int i, int j, int b){
  if(cur[i][j] == -1){
    cur[i][j]=b;
    if(s[i] == 0 && cu[i] && b == 1) ci[i]=0;
    if(s[i] == 0 && !cu[i] && b == 0) ci[i]=0;
    
    if(s[i] == 1 && !cu[i] && b == 0) ci[i]=0;
    if(s[i] == 1 && cu[i] && b == 1) ci[i]=0;
    
    if(t[j] == 0 && vu[j] && b == 1) cj[j]=0;
    if(t[j] == 0 && !vu[j] && b == 0) cj[j]=0;
      
    if(t[j] == 1 && !vu[j] && b == 0) cj[j]=0;
    if(t[j] == 1 && vu[j] && b == 1) cj[j]=0;
    
    ci[i]--;
    cj[j]--;
    return;
  }
  if(cur[i][j] != b){
    cout << "-1";
    exit(0);
  }
}

int ni[N], nj[N];

void solve(ull bit){
  for(int i = 1; i <= n; i ++ ){
    cu[i] = (u[i] & bit);
    vu[i] = (v[i] & bit);
  }
  for(int i = 1; i <= n; i ++ ) for(int j = 1; j <= n; j ++ ) cur[i][j]=-1, ci[i]=cj[j]=n;
  for(int i = 1; i <= n; i ++ ){
    if(s[i] == 0 && cu[i])
      for(int j = 1; j <= n; j ++ ){
        setbit(i, j, 1);
      }
    if(s[i] == 1 && !cu[i])
      for(int j = 1; j <= n; j ++ ){
        setbit(i, j, 0);
      }
    if(t[i] == 0 && vu[i])
      for(int j = 1; j <= n; j ++ )
        setbit(j, i, 1);
    if(t[i] == 1 && !vu[i])
      for(int j = 1; j <= n; j ++ ){
        setbit(j, i, 0);
      }
  }
  for(int i = 1; i <= n; i ++ ){
    ni[i]=-1,nj[i]=-1;
    if(ci[i] >= 0)
      ni[i]=cu[i];
    if(cj[i] >= 0)
      nj[i]=vu[i];
    //cout << ni[i] << " " << nj[i] << "\n";
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      if(cur[i][j] == -1){
        if(ci[i] < 0 && cj[j] < 0) setbit(i,j,0);
        if(ci[i] > 0 && cj[j] < 0) setbit(i,j,ni[i]);
        if(ci[i] < 0 && cj[j] > 0) setbit(i,j,nj[j]);
        if(ci[i] > 0 && cj[j] > 0){
          if(ci[i] <= cj[j]){
            setbit(i,j,ni[i]);
          }
          else{
            setbit(i,j,nj[j]);
          }
        }
      }
    }
  }
  for(int i = 1; i <= n; i ++ ){
    if(ci[i] >= 0 || cj[i] >= 0){
      cout << "-1\n";
      exit(0);
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      if(cur[i][j]) ans[i][j] |= bit;
    }
  }
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 1; i <= n; i ++ )
    cin >> s[i];
  for(int i = 1; i <= n; i ++ )
    cin >> t[i];
  for(int i = 1; i <= n; i ++ )
    cin >> u[i];
  for(int i = 1; i <= n; i ++ )
    cin >> v[i];
  for(int lg = 63; lg >= 0 ;lg -- ){
    solve((1ll << lg));
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n ; j ++ ){
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
