#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
//map<key,value>


int main(){
  int n,k;
  cin >> n;
  string s;
  cin >> s;
  cin >> k;
  for(int i=0;i<n;i++){
    if(s[i]!=s[k-1]){
      s[i]='*';
    }
  }
  cout << s;
}