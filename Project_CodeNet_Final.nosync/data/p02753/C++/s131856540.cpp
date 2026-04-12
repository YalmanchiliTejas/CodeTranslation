#include <bits/stdc++.h>
using namespace std;

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

int main(){
  string s;cin>>s;
  for(char p:s)for(char q:s)if(p!=q)fin("Yes");
  fin("No");
}
