#include<iostream>
using namespace std;

int main(void){
  int n,k; cin >> n;
  string str; cin >> str;
  cin >> k;
  //cout << str[1] << endl;

  char replace = str[k-1];
  string ret = "";
  for( string::iterator itr=str.begin(); itr!=str.end(); ++itr){
    if ( *itr != replace) ret += '*';
    else ret += *itr;
  }
  cout << ret << endl;

  return 0;
}