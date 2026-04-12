#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<bool>> g(2*m,vector<bool>(2*m,false));
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g.at(a).at(b) = g.at(b).at(a) = true;
  }
  vector<int> per(n);
  for(int i=0;i<n;i++) per.at(i) = i;
  
  int cnt=0;
  do{
    if(per.at(0)!=0) break;
    bool flag = true;
    for(int i=0;i<n-1;i++){
      int from = per.at(i);
      int to = per.at(i+1);
      if(!g.at(from).at(to)) flag = false;
    }
    if(flag) cnt++;
  }while(next_permutation(per.begin(),per.end()));
  
  cout << cnt << endl;
  
}