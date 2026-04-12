#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  int n,i,j,tal[26],al[26];string s;char z;cin >> n;
  for(i=0;i<26;i++) tal[i] = 50;
  for(i=0;i<n;i++){
    cin >> s;
    for(j=0;j<26;j++) al[j] = 0;
    for(j=0;j<s.size();j++) al[s[j]-'a']++;
    for(j=0;j<26;j++) tal[j] = min(tal[j],al[j]);
  }
  for(i=0;i<26;i++){
    z = i+int('a');
    for(j=0;j<tal[i];j++) cout << z;
  }
  cout << endl;
}