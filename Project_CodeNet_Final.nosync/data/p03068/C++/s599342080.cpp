#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,k;
  string s;
  char c;
  cin >> n >> s >> k;
  c = s[k-1];
  for(int i=0;i<n;i++){
    if(c==s[i]) cout << s[i];
    else cout <<"*";
  }
  cout << "\n";
}
