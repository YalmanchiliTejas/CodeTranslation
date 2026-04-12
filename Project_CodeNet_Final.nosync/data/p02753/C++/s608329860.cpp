#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int a=0;
  if(s[0]!=s[1]) a++;
  if(s[1]!=s[2]) a++;
  if(s[0]!=s[2]) a++;
  if(a!=0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
