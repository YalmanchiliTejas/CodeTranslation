#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;

const int mx=100010;
const ll mod=1e9+7;

int n,m;
bool done[10];
vector<int> v[10];
int ans=0;

void dfs(int x, int cnt){
  if(cnt==n){ans++;}
  for(auto to:v[x]){
    if(!done[to]){
      done[to]=true;
      dfs(to,cnt+1);
      done[to]=false;
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  done[1] = true;
  dfs(1,1);

  cout << ans << endl;
  return 0;  
}