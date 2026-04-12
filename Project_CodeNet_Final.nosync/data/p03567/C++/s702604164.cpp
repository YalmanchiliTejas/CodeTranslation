#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int n,i;
  string s;
  
  cin >> s;
  n=s.size();
  
  for (i=0;i<n-1;i++){
    if (s[i]=='A' && s[i+1]=='C'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  
  return 0;
}