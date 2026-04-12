#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vector<vi> to(n);
  rep(i,m){
    int a,b; cin >> a >> b;
    --a;  --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  int ans = 0;
  vi num(n-1); rep(i,n-1) num[i] = i+1;
  do{
    int now = 0;
    vi node(n);
    node[0] = 1;
    rep(i,n-1){
      for(auto next : to[now]){
        if(next != num[i]) continue;
        now = next;
        node[next] = 1;
        break;
      }
    }
    bool ok = true;
    rep(i,n) if(!node[i]) ok = false;
    if(ok) ans++;
  }while(next_permutation(all(num)));
  cout << ans;
  cout << "\n";
  return 0;
}
