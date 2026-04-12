#include<bits/stdc++.h>
using namespace std;
bool isVowel(char c){
  string vowels("aeiou");
  for(char vowel:vowels)if(vowel==c)return true;
  return false;
}
main(){
  char c;
  cin>>c;
  cout<<(isVowel(c)?"vowel":"consonant")<<endl;
}
