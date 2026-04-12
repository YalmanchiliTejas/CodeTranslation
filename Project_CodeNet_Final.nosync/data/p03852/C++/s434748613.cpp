#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin>>c;
  string result;
  
  if(c=='a' || c=='e' || c=='i' || c=='u'|| c=='o'){
  	 result="vowel";
  }
  else{
  	 result="consonant";
  }
  
  cout<<result<<endl;
}