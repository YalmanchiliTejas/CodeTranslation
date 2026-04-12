#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s[60];
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> s[i];
  }
  char kekka[60]; 
  char alp = 'a';
  char b[30];
  for(int i = 1;i <= 26;i++){
    b[i] = alp;
    alp++;
  }
  int mozisu[30];
  for(int i = 1;i <= 26;i++){
    mozisu[i] = 100;
  }
  for(int k = 1;k <= 26;k++){
    for(int i = 0;i < n;i++){
      int cur = 0;
      for(int j = 0;j < s[i].size();j++){
        if(s[i].at(j) == b[k]){
          cur++;
        }
      }
      mozisu[k] = min(mozisu[k],cur);
    }
  }
  
  for(int i = 1;i <= 26;i++){
    for(int j = 1;j <= mozisu[i];j++){
      cout << b[i];
    }
  }
}