#include<iostream>
using namespace std;
int main(){
  char s;
  cin >> s;
  char v[] = { 'a', 'i', 'u', 'e', 'o', '\0' };
  int i=0;
  while(i<5){
    if(s==v[i]){
      cout << "vowel" << endl;
      break;
    }
    if(i==4){
      cout << "consonant" << endl;
    }
    i+=1;
  }
  return 0;
}