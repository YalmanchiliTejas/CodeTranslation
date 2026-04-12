#include<iostream>
using namespace std;
int main(){
  char ch;
  while(cin >> ch){
    if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'){
      cout << "vowel";
      
    }else{
      cout << "consonant";
    }
  }
  
}
