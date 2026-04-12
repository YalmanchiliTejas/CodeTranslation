#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  int flag = 0;
  string vo = "aeiou";
  cin >> c;
  
  for(int i=0; i<vo.size(); i++){
    if(vo.at(i)==c){
      flag = 1;
    }
  }
  if(flag==1){
  	cout << "vowel" << endl;
  }else{
  	cout << "consonant" << endl;
  }
    
}

