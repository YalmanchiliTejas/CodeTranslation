#include<iostream>
#include<string>
using namespace std;

int main(){
  int n, k;
  string s;
  cin>> n;
  cin>> s;
  cin>> k;

  size_t size = s.length();
  for(int i=0;i<size;i++){
    if(s[i] != s[k-1])
      s[i] = '*';
  }

  cout<<s<<endl;

  return 0;
}
