#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  
  vector<vector<bool>> check(N,vector<bool>(N,false));
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    check.at(a-1).at(b-1)=true;
    check.at(b-1).at(a-1)=true;
  }
  
  vector<int> p(0);
  for(int i=1; i<=N; i++){
    p.push_back(i);
  }
    
  int num=1;
  for(int i=1; i<N; i++){
    num*=i;
  }
  
  int ans=0;
  for(int i=0; i<num; i++){
    if(i>0){
      next_permutation(p.begin(), p.end());
    }
    for(int j=0; j<N-1; j++){
      int x=p.at(j)-1, y=p.at(j+1)-1;
      if(check.at(x).at(y)==false) break;
      if(j==N-2){
        ans++;
      }
    }
  }
  cout << ans << endl;
}