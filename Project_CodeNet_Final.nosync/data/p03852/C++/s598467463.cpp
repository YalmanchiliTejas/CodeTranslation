#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0; i<n; i++)
#define out(x) cout<<(x)<<"\n"

int main(){
  char c;
  cin>>c;
  if(c=='a' || c=='i' || c=='e' || c=='o' || c=='u'){
    out("vowel");
  }
  else{
    out("consonant");
  }
}