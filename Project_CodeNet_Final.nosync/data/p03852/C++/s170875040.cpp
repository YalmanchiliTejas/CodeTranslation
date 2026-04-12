#include<iostream>
using namespace std;

int main(void) {
char c;
cin >> c;
string str;
if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') str = "vowel";
else str="consonant";
cout << str << endl;
return 0;
}