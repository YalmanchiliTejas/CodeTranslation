#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char z;
  string ans;
  cin >> z;
  if(z=='a'||z=='i'||z=='u'||z=='e'||z=='o'){
  	ans = "vowel";
  }
  else{
  	ans = "consonant";
  }
 cout << ans << endl; 
}