#include<bits/stdc++.h>
using namespace std;
int main(){
  int i;
  int z;
  string s = "abcdefghijklmnopqrstuvwxyz";
  int min_num[26];


  cin >> z;
  for (i = 0; i<z;i++){
    string s_in;
    cin >> s_in;
    int min_s[26] = {0};

    for (int x = 0;x< (int)s.size();x++){
      for (int q = 0; q < (int)s_in.size();q++){
        if(s[x] == s_in[q]){
          min_s[s[x]-'a']++;
        }
      }
    }
    if(i == 0){
      for (int o = 0;o<26;o++){
        min_num[o] = min_s[o];
      }
    }
    for (int o = 0; o < 26; o++){
      /* code */
      min_num[o] = min(min_num[o], min_s[o]);
    }
  }
  for (i = 0;i < 26;i++){
    for(int q = 0; q < min_num[i]; q++){
    cout << s[i];
  }
  }
  cout << endl;
  return 0;
}
