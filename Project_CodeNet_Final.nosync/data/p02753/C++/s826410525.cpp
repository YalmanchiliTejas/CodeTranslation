#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main(void) {
 string s;
 cin >> s;
 if(strcmp(s.c_str(), "AAA") == 0 || strcmp(s.c_str(), "BBB") == 0) {
   cout << "No" << endl;
   return 0;
 }
 cout << "Yes" << endl;
  
}