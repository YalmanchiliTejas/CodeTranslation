#include<bits/stdc++.h>
using namespace std;

int main(){
  char c;
  cin >> c;
  string ans = "consonant";
  vector<char> vc = {'a','e','i','o','u'};
  for(auto& x : vc){
    if(c==x)
      ans = "vowel";
  }
  cout << ans << endl;
}