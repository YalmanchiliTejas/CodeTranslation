#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int n;
  string c;
  cin >> n;
  int s[50][26]={};
  int ans[26];
  for(int i=0; i<n; i++){
    cin >> c;
    for(int j=0; j<c.size(); j++){
      s[i][c[j]-'a']++;
    }
  }

  int mina[26];
  for(int i=0; i<26; i++){
    mina[i]=100000000;
  }

  for(int i=0; i<26; i++){
    for(int j=0; j<n; j++){
      mina[i]=min(s[j][i], mina[i]);
    }
  }

  for(int i=0; i<26; i++){
    for(int j=0; j<mina[i]; j++){
      cout << (char)('a'+i);
    }
  }
  cout << endl;
  return 0;
}
