#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  char s[n];
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  int a;
  cin>>a;
  a--;
  for(int i=0;i<n;i++){
    if(s[i]!=s[a]) s[i]='*';
    cout<<s[i];
  }
  cout<<endl;
}