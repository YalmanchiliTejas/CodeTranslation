#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  string s;
  cin >> n >> s >> k;
  
  char point;
  point = s.at(k-1);
  
  for(int i; i<n; i++){
    if(s.at(i) != point){
      s.at(i) = '*';
    }
  }
  
  cout << s << endl;
}