#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int n,k;
  cin >> n >> s >> k;

  char sk = s[k-1];

  for(int i = 0; i < n; i++)
  {
      if(s[i]!=sk){
          s[i]='*';
      }
  }

  cout << s << endl;  
}