#include<iostream>
using namespace std;
int main(){
  string s; cin >> s;
  int n = (int)s.size();
  bool f = false;
  for(int i = 0; i < n - 1; ++i){
    f |= s[i] == 'A' && s[i+1] == 'C';
  }
  cout << (f?"Yes":"No") << endl;
}