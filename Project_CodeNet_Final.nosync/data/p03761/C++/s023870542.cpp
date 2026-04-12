#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string a[n];
  int b[26];
  for(int i=0;i<26;i++) b[i]=100;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++){
    int c[26]={};
    for(int j=0;j<a[i].size();j++) c[a[i].at(j)-97]++;
    for(int k=0;k<26;k++) b[k] = min(b[k],c[k]);
  }
  for(int i=0;i<26;i++){
    for(int j=0;j<b[i];j++) cout << char(97+i);
  }
  cout << endl;
}
