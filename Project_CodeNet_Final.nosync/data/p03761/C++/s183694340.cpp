#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int n; cin >> n;
  int al[26], temp[26];
  for(int i=0; i<26; i++){
    al[i] = 100;
    temp[i] = 0;
  }

  string s;
  for(int i=0; i<n; i++){
    cin >> s;
    for(int j=0; j<s.length(); j++){
      temp[s[j]-'a']++;
    }
    for(int j=0; j<26; j++){
      al[j] = min(al[j], temp[j]);
      temp[j]=0;
    }
  }

  for(int i=0; i<26; i++){
    if(al[i]){
      for(int j=0; j<al[i]; j++) cout << (char)(i+'a');
    }
  }
  cout << endl;

  return 0;
}
