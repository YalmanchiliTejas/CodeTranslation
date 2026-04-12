#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    char moji[] = "aeiou";
    string s;
    cin >> s;
    int check = 0;
    for(int i = 0; i < 5; i++){
        if(s[0] == moji[i])
            check++;
    }
    if(check != 0)
        cout << "vowel" << endl;
    if(check == 0)
        cout << "consonant" << endl;
    return 0;
}