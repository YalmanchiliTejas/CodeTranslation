#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;
int main(){
  string s;
  cin >> s;
  int c=0;
  rep(i,0,s.size()-1){
    if(s.at(i)=='A' && s.at(i+1)=='C') c++;
  }
  if(c==0) co("No");
  else co("Yes");
  
  
  return 0;
}
