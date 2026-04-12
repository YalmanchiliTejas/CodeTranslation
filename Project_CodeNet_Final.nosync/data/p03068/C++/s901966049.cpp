#include <iostream>
using namespace std;
int main(){
  int n,k;string s;cin>>n>>s>>k;k--;
  for(int i = 0; n > i; i++){
    if(s[k] != s[i]){
      s[i] = '*';
    }
  }
  cout << s << endl;
}