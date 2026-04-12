#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;

int main(){
    char c;

    cin >> c;

    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}
