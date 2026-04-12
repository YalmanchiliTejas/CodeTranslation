#include<bits/stdc++.h>
using namespace std;

int main () {
   char c;
   cin >> c;
   string str1, str2;
   str1 = "vowel";
   str2 = "consonant";

   if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
       cout << str1 << endl;
   }

   else {
       cout << str2 << endl;
   }

}