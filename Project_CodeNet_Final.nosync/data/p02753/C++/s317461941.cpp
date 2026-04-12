#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i; i < (n); i++)
using ll = long long;
int main(){
  string a;
  cin >> a;
  if(a.at(0) == a.at(1) && a.at(1) == a.at(2)){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
  return 0;
}
