#include <iostream>
#include <string>

using namespace std;

int main(){
  int n,k,i;
  string s;
  cin >> n >> s >> k;
  char c = s[k-1];
  for(i=0;i<n;i++){
    if(s[i]!=c) s[i] = '*';
  }
  cout << s << endl;
  return 0;
}
