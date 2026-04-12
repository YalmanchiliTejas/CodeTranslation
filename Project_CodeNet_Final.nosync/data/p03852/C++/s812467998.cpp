#include <iostream>
#include <string>
#include <vector>
using namespace std;

char c;

int main(){

    cin >> c;

    if(c == 'a'||c == 'i'||c == 'e'||c == 'u'||c == 'o'){
        cout << "vowel" << endl;
    }
    else{
        cout << "consonant" << endl;
    }
    return 0;
}