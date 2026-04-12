#include<bits/stdc++.h>
using namespace std;

int main(){
  char s[2];
  for(int i=0; i<3; i++)
  {
    cin >>s[i];
  }
  if(s[0]==s[1] && s[1]==s[2]){cout <<"No";}
  else{cout <<"Yes";}
}