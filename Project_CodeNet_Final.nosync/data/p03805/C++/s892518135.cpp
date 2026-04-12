#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll MOD=1e9+7;
const int INF=1<<30;

bool con[8][8];

int main(){
  int N,M;
  cin >> N >> M;
  rep(i,M){
    int a,b;
    cin >> a >> b;
    a--; b--;
    con[a][b]=1;
    con[b][a]=1;
  }
  vector<int> v(0);
  for(int i=1;i<N;i++){
    v.push_back(i);
  }
  int ans=0;
  do{
    bool flag=true;
    if(con[0][v[0]]==0) flag=false;
    for(int i=0;i<=N-3;i++){
      if(con[v[i]][v[i+1]]==0) flag=false;
    }
    if(flag) ans++;
  }while(next_permutation(all(v)));
  cout << ans << endl;
}