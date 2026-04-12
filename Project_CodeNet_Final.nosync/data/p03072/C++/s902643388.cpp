#include <bits/stdc++.h>
using namespace std;
int main(){
  
  int n;
  cin >> n;
  
  vector<int> v(n);
  for(int i; i < n; i++)
    cin >> v.at(i);
  
  int s = 0;
  int t = 0;
  int u = 0;
  
  while(t < n){
    while(u < t){
      if(v.at(u) <= v.at(t))
        u++;
      else
        break;
    }
    if(u == t)
      s++;
    t++;
    u = 0;
  }
  cout  << s << endl;
}
        