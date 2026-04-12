#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void test_G(const vector<int> &num,const vector<set<int>> &G,const int &n){
  bool ck = true;
  for(int i=0;i<n-1;i++){
    if(G.at(num.at(i)).count(num.at(i+1))) continue;
    else{
      ck = false;
      break;
    }
  }
  if(ck) cnt++;
}
  

int main() {
  int n,m;
  cin >> n >> m;
  vector<set<int>> G(n+1);
  vector<int> num(n);
  
  for(int i=0;i<n;i++){
    num.at(i) = i+1;
  }
  
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    G.at(a).insert(b);
    G.at(b).insert(a);
  }
  
  do{
    if(num.at(0) == 1) test_G(num, G, n);
  }while(next_permutation(num.begin(),num.end()));
  
  cout << cnt << endl;  
    
}
