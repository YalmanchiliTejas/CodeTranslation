#include<iostream>
#include<string>
using namespace std;

int main(void){
  int n; cin>>n;
  string s; cin>>s;
  int k; cin>>k;
  for(int i=0; i<s.length(); ++i){
    if( s[i] != s[k-1]) s[i] = '*';
  }
  cout << s << endl;
}

