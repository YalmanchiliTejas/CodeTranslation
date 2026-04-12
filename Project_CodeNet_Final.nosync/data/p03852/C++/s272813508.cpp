#include <bits/stdc++.h>
using namespace std;
 
// vector<int> vec(3); = vector<int> vec={0,0,0}
// vec.at()
// sort(num.begin(),num.end(), greater<int>());
// reverse(num.begin(),num.end());
 
// 切り上げ　a/b+1
//  1からNの総和　N*(N+1)/2
 
int main() {
  char c;
  cin >> c;
  
  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
  	cout << "vowel" << endl;
  }
  else{
  	cout << "consonant" << endl;
  }
}