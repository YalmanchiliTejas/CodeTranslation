#include"bits/stdc++.h"
using namespace std;

int main(){
  char a;
  cin >> a;
  string b = "aiueo";
  for (int i=0; i<5; i++){
    if (a==b[i]){
      cout << "vowel" << endl;
      exit(0);
    }
  }
  cout << "consonant" << endl;

}