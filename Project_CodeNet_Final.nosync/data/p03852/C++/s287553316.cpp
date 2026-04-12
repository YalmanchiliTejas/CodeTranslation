#include <iostream>

using namespace std;

int main(){
    string vowel = "aiueo";
    char c;
    cin >> c;
    for (int i=0; i < vowel.size(); i++){
        if (c == vowel.at(i)){
            cout << "vowel" << endl;
            return 0;
        }
    }

    cout << "consonant" << endl;
}
