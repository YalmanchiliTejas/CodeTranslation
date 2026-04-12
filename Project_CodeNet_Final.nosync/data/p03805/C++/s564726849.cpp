#include <bits/stdc++.h>
using namespace std;

int N, M;
vector< vector<bool> > route(0);
vector< bool > reached(0);

void search(int &count, int P){
  
  reached.at(P-1) = true;
  for(int i=0; i<N; i++){
    if(!reached.at(i)) goto skip;
  }
  count++;
  
  skip:
  
  for(int i=0; i<N; i++){
    if(route.at(P-1).at(i) && !reached.at(i)) search(count, i+1);
  }
  
  reached.at(P-1) = false;
  return;
  
}

int check(){
  
  int count = 0;
  search(count, 1);
  return count;
  
}

int main() {
  
  cin >> N >> M;
  for(int i=0; i<N; i++){
    reached.push_back(false);
    route.push_back(vector<bool>(N, false));
  }
  for(int i=0; i<M; i++){
    int a, b; cin >> a >> b;
    route.at(a-1).at(b-1) = true;
    route.at(b-1).at(a-1) = true;
  }
  
  int ans = check();
  
  cout << ans << endl;
  
}