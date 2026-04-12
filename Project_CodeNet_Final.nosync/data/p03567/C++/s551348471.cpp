#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;
int main(){
  bool flag = false;
  string s;
  cin >> s;
  r(i,s.length()-1){
    if(s.at(i)=='A'&&s.at(i+1)=='C'){
      cout << "Yes"<<endl;
      flag=true;
      break;
    }
  }
  if(!flag)cout << "No"<<endl;
}