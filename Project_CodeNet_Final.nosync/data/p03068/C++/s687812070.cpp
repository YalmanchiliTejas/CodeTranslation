#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<char> s(n);
  for(int i=0;i<n;i++){
   cin >> s.at(i);
  }
  
  int k;
  cin >> k;
  for(int i=0;i<n;i++){
   if(s.at(i)!=s.at(k-1)){
    s.at(i)='*'; 
   }
    cout << s.at(i);
  }
  
  
}