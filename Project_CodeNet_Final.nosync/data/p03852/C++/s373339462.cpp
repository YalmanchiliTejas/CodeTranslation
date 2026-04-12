#include <iostream>
#include <string>
#include <cstring>
 using namespace std;

 int main()
 {
    char c;
    cin>>c;
    if(strchr("aeiou",c)) cout<<"vowel";
    else cout<<"consonant";
 }
