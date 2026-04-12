#include <bits/stdc++.h>
using namespace std;

int main(){
  char c;
  cin>>c;
  string ans = "consonant";
  if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
    ans = "vowel";
  }
  cout<<ans<<endl;
}