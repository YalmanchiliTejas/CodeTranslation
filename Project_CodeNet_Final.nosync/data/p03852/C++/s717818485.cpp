#include <iostream>
using namespace std;

char vowel[] = {'a', 'i', 'u', 'e', 'o'};
 int main(){
   char c;
   cin >> c;
   int j = 0;
   for(int i = 0; i < sizeof vowel; i++){
     if(vowel[i]==c)j=1;
   }
   if(j)cout << "vowel" << endl;
   else cout << "consonant" << endl;
 }
