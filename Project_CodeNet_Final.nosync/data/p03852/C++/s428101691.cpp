#include<iostream>
using namespace std;

int main(){
    string str;

    cin >> str;

    if(str[0] == 'a' || str[0] == 'i' || str[0] == 'u' || str[0] == 'e' || str[0] == 'o'){
        cout << "vowel\n";
    }
    else{
        cout << "consonant\n";
    }

    return 0;
}