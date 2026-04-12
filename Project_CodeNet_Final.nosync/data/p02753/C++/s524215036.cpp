#include <bits/stdc++.h>
using namespace std;

string s;
int c, c2;

int main() {
  cin>>s;
  for(int i=0; i<3; i++){
    if(s[i]=='A'){
      c+=1;
    }
    else if(s[i]=='B'){
      c2+=1;
    }
  } 
  if(c==2||c2==2){
    cout<<"Yes\n";
  }
  else{
    cout<<"No\n";
  }
}