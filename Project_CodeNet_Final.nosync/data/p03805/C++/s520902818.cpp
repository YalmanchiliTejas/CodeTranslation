#include<bits/stdc++.h>
using namespace std;

int N, M;
map<int, set<int> > mp;
int ans = 0;
set<int> alp;

void dps(int nxt){
  alp.insert(nxt);
  if (alp.size() == N){
    ans++;
  }
  else{
    for (int x: mp[nxt]){
      if (alp.find(x) == alp.end()){
        dps(x);
      }
    }
  }
  alp.erase(nxt);
}

int main(){
  cin >> N >> M;
  for (int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    mp[a].insert(b);
    mp[b].insert(a);
  }
  dps(1);
  cout << ans << endl;
}
