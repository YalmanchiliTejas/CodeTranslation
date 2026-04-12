#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,i;
  string s;
  cin >> n;
  cin >>s;
  cin >> k;
  for (i =0 ;i<n;i++){
    if(s[i] != s[k-1]){
      s[i] = '*';
    }
  }
  cout << s << endl;
}