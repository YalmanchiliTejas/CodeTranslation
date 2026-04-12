#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  string s;
  cin >> s;
  rep(i,s.size()){
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
      cout << "vowel" << endl;
      return 0;;
    }
  }
  cout << "consonant" <<endl;
  return 0;

}
