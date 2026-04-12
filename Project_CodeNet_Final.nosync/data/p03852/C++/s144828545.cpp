#include <iostream>
using namespace std;
int main(){
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char c;
    cin >> c;
    for(int i = 0; i < 5; i++) {
        if(c == vowels[i]){
            cout << "vowel";
            return 0;
        }
    }
    cout << "consonant";
    return 0;
}