#include <bits/stdc++.h>
using namespace std;

int c=0, N;
map<int, vector<int>> m;

void osp(int a, int t, set<int> s) {
  for(int x : m.at(a)) {
    int z=t+1;
    set<int> y;
    for(auto n : s)
      y.insert(n);
    if(!y.count(x)) {
      y.insert(x);
      if(z==N)
        c++;
      else
        osp(x, z, y);
    }
  }
}

int main() {
  int M,i,a,b;
  cin >> N >> M;
  
  for(i=0; i<M; i++) {
    cin >> a >> b;
    if(!m.count(a))
      m[a].push_back(b);
    else
      m.at(a).push_back(b);
    if(!m.count(b))
      m[b].push_back(a);
    else
      m.at(b).push_back(a);
  }

  set<int> seen;
  seen.insert(1);
  osp(1,1,seen);

  cout << c << endl;
}