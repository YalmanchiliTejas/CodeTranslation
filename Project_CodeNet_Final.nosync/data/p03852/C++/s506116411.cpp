#include <bits/stdc++.h>
using namespace std;

int main(){
  string c;
  cin >> c;
  int flag = 1;
  vector<string> p = {"a","i","u","e","o"};
  for(int i=0;i<p.size();i++){
    if (c==p.at(i)){
      flag = 0;
    }
  }
  if (flag==1){
    cout << "consonant" << endl;
  }else{
    cout << "vowel" << endl;
  }
}