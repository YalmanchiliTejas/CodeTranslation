#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,m,s;
  cin >> n;
  vector<int> h(n);
  s=1;
  cin >> h.at(0);
  m=h.at(0);
  for(i=1;i<n;i++){
    cin >> h.at(i);
    if(m<=h.at(i)){
      s++;
      m=h.at(i);
    }
  }
  
  cout << s << endl;
}