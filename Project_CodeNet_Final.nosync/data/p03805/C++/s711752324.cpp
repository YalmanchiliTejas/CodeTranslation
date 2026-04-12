#include <bits/stdc++.h>
using namespace std;

int N,M;
vector< vector<int> > v;
vector<bool> flag;
int64_t ans=0;

void visit(int i){
  static int count=0;
  count++;
  flag.at(i)=true;
  if(count==N){
    ans++;
  }
  for(auto j : v.at(i)){
    if(!flag.at(j)){
      visit(j);
    }
  }
  count--;
  flag.at(i)=false;
}

int main(){
  cin >> N >> M;
  v.resize(N+1);
  flag.resize(N+1);
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    v.at(a).push_back(b);
    v.at(b).push_back(a);
  }
  visit(1);
  cout << ans << endl;
  return 0;
}
