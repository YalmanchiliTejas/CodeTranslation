#include<bits/stdc++.h>
using namespace std;

int main(){
  char s;
  string ans;
  cin >> s;
  if( s=='a' || s=='i' || s=='u' || s=='e'|| s=='o'){
    ans="vowel";
  }
  else{
    ans="consonant";
  }
  cout << ans << endl;
}