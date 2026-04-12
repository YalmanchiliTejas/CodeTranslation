#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  set<char> s;
  for(int i=0;i<S.size();i++){
    s.insert(S.at(i));
  }
  if(s.size()==2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
