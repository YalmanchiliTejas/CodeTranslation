#include <bits/stdc++.h>
using namespace std;
 
int main(){
  char a;
  cin >> a;
  char vo[] = {'a','i','u','e','o'};
  for(int i=0; i<5; i++){
    if(a==vo[i]){
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}
