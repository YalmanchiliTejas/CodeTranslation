#include <iostream>
#include <string>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  int a = 0;
  cin >> s;
  for (int i = 0; i < s.size()-1; i++){
    if(s[i]=='A' and s[i+1]=='C'){
      a = 1;
    }
  }
  if(a==1){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
}
