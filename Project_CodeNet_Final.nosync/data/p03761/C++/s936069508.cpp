#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> ans(26);
  for(int i=0; i<26; i++) ans.at(i)=50;
  for(int i=0; i<N; i++){
    string S;
    cin >> S;
    vector<int> cnt(26);
    for(int i=0; i<S.size(); i++){
      cnt.at(S.at(i)-97)++;
    }
    for(int i=0; i<26; i++){
      ans.at(i)=min(ans.at(i),cnt.at(i));
    }
  }
  string W;
  for(int i=0; i<26; i++){
    for(int j=0; j<ans.at(i); j++) W += (char)(i+97);
  }
  cout << W << endl;
}