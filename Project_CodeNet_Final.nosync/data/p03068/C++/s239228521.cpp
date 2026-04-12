#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int n,k,i;
  string s;
  
  cin >> n >> s >> k;
  
  for (i=0;i<n;i++){
    if (s[i]!=s[k-1]) s[i]='*';
  }
  
  cout << s << endl;
  
  return 0;
}