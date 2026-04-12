#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> P;
  for(int i=0;i<N;i++) P.push_back(i);
  map<int,bitset<8>> m;
  for(int i=0;i<M;i++){
    int x,y;
    cin >> x >> y;
    x--,y--;
    if(!m.count(x)) m[x];
    if(!m.count(y)) m[y];
    m[x].set(y);
    m[y].set(x);
  }
  int tt = 0;
  do{
    if(P[0] != 0) continue;
    bool tf = false;
    for(int i=1;i<N;i++){
      if(!m[P[i-1]].test(P[i]))break;
      if(i == N-1) tf = true;
    }
    if(tf)tt++;
  } while(next_permutation(all(P)));
  cout << tt << endl;
}


