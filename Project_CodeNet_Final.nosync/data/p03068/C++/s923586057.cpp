#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  string s;
  cin >> n >> s >> k;
  for(int i = 0;i < n;i++){
   if(s.at(k-1) == s.at(i)){
     continue;
   }else{
     s.at(i) = '*';
   }
  }
    cout << s << endl;

  return 0;
}