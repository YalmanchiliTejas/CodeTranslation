#include <bits/stdc++.h>
using namespace std;

int a,b;
string s;

int main(){
  cin>>a>>s>>b;
  for(int i=0;i<a;i++)cout<<(s[i]==s[b-1]?s[i]:'*');
}