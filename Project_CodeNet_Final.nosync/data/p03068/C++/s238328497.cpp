#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,k;
  string s;
  cin >> n >> s >> k;
  char a = s[k-1];
  for(long long i = 0; i < n; i++){
    if(s[i]!=a) s[i]='*';
  }
  cout << s << endl;
}