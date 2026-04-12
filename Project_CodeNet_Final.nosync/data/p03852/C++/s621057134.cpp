#include <iostream>
using namespace std;
string str;
int main(void){
    // Your code here!
    cin >> str;
    if(str[0] == 'a' || str[0] == 'i' || str[0] == 'u' || str[0] == 'e' || str[0] == 'o') cout << "vowel" << endl;
    else cout << "consonant" << endl;
}
