#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int n;
vi x,y;
int l[110],t[110],r[110],b[110];
ll rec[110][110];
const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};

void dfs(int py, int px, ll col){
  if(rec[py][px] != col)return;
  rec[py][px] = -1;

  rep(i,4){
    int ny = py + dy[i], nx = px + dx[i];
    if(ny<0 || nx<0 || ny>=(int)y.sz || nx>=(int)x.sz)continue;
    dfs(ny,nx,col);
  }
}

int main(){
  cin.tie(0);
  std::ios::sync_with_stdio(0);

  while(cin >> n,n){
    x.clear(); y.clear();
    x.pb(-1); y.pb(-1);
    rep(i,n){
      cin >> l[i] >> t[i] >> r[i] >> b[i];
      x.pb(l[i]); x.pb(r[i]);
      y.pb(t[i]); y.pb(b[i]);
    }

    sort(all(x));
    x.erase(unique(all(x)),x.end());
    sort(all(y));
    y.erase(unique(all(y)),y.end());

    memset(rec,0,sizeof(rec));

    rep(i,n){
      l[i] = lower_bound(all(x),l[i]) - x.begin();
      r[i] = lower_bound(all(x),r[i]) - x.begin();
      t[i] = lower_bound(all(y),t[i]) - y.begin();
      b[i] = lower_bound(all(y),b[i]) - y.begin();
      for(int j=b[i];j<t[i];j++){
	for(int k=l[i];k<r[i];k++)rec[j][k] |= 1LL<<i;
      }
    }

    int ans = 0;
    rep(i,y.sz)rep(j,x.sz){
      if(rec[i][j]>=0)dfs(i,j,rec[i][j]), ans++;
    }
    cout << ans << endl;
  }
}