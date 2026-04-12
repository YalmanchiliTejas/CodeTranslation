#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    // Your code here!
   char a;
   
   cin >> a;
   if( a == 'a' || a == 'i'|| a == 'u' || a == 'e' || a == 'o' ){
       cout << "vowel" << endl;
   }else {
       cout << "consonant" << endl;
   }
}
