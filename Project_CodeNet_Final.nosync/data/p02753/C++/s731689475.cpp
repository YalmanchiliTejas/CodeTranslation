#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i ,n) for(int i = 0; i < (int)(n); i++)

int main(){
  string S;
  cin >> S;
  
  int flag = 0;
  rep(i, S.size()-1){
    if(S.at(i) != S.at(i+1)){
      flag = 1;
    }
  }
  
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
