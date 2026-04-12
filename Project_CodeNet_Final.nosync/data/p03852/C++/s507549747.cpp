#include<bits/stdc++.h>
#include<string>
using namespace std;

main(){
  int i,flag=0;
  char c;
  vector<char> vow={'a','e','i','o','u'};
  cin >> c;
  for(i=0;i<5;i++){
    if(c==vow[i]) {
      flag = 1;
      break;
    }
  }
  if(flag) cout << "vowel" << endl;
  else cout << "consonant" << endl;
}