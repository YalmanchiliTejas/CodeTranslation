#include <bits/stdc++.h>
using namespace std;

int a[60][30];
int main() {
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    int num=s.size();
    for(int j=0;j<num;j++){
      int x=s[j]-'a';
      a[i][x]++;
    }
  }
  for(int i=0;i<26;i++){
    int kazu=INT_MAX;
    for(int j=0;j<n;j++){
      kazu=min(kazu,a[j][i]);
    }
    for(int k=0;k<kazu;k++){
      char c=i+'a';
      cout<<(char)c;
    }
  }
  cout<<endl;
  return 0;
}
    
