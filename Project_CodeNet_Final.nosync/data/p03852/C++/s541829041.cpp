#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  char s[6]="aeiou",a;
  cin>>a;
  for(int i=0;i<5;i++){
    if(a==s[i]){
      cout<<"vowel";
      return 0;
    }
  }
  cout<<"consonant";
}