#include <iostream>
using namespace std;

int main() {
  char c;cin>>c;
  bool ans=false;
  for(char a:{'a','i','u','e','o'}){
    if(a==c) ans = true;
  }

  if(ans) cout << "vowel" << endl;
  else cout<<"consonant"<<endl;
  return 0;
}
