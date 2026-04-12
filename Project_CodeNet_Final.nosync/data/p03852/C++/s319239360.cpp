#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  string A; A="aiueo";
  int q;q=0;
  
  for (int i=0;i<5;i++){
  char a;a=A.at(i);
   if (c == a){
     cout << "vowel" << endl;
     q++;
   }
  }
  if(q!=1) {
    cout << "consonant" << endl;
  }
}
