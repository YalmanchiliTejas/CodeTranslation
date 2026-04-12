#include<bits/stdc++.h>

using namespace std;

int main(){
  char c[1];
  cin >> c;

  if((strcmp(c,"a")) == 0 || (strcmp(c,"i")) == 0 || (strcmp(c,"u")) == 0 || (strcmp(c,"e")) == 0 || (strcmp(c,"o")) == 0)
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
}