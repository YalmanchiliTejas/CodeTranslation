#include<iostream>
using namespace std;
 
int main(void){
  char in;
  cin >> in;
  if(in == 'a'|| in == 'i'||in == 'u'||in == 'e'||in == 'o')cout << "vowel"<<endl;
  else cout << "consonant" << endl;
  return 0;
}