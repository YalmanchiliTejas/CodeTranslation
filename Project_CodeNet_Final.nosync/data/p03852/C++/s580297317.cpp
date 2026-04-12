#include <iostream>
using namespace std;

int main(){
    char c;
    cin >> c;
    string vowel = "aeiou";
    for(int i=0; i<vowel.size(); i++){
        if (vowel.at(i) == c){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}