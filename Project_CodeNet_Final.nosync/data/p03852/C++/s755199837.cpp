#include<iostream>
#include<string>

using namespace std;

int main(void){
    string vowel = "aeiou";
    char c;
    cin >> c;
    for(int i = 0; i < vowel.length(); i++){
        if(vowel[i] == c){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}