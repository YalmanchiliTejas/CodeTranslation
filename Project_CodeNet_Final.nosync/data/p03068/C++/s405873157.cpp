#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main() {
  int n,k;
  string s;
  cin >> n >> s >> k;
  char a=s[k-1];
  for(int i=0; i<n; i++) {
    if(s[i]!=a) {
      s[i]='*';
    }
  }
  cout << s << endl;
}
