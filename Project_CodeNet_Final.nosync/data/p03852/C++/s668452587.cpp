#include <bits/stdc++.h>
using namespace std;

int main(){
  char vowel;
  cin >> vowel;
  
  if(vowel=='a' || vowel=='i' || vowel=='u' || vowel=='e' || vowel=='o'){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
}