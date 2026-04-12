#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s;
  int n,k;
  cin >> n >> s >> k;
  char target = s[k-1];
  for(int i=0;i<n;i++){
    if(s[i]!=target){
      s[i] = '*';
    }
  }
  cout << s;
  return 0;
}
