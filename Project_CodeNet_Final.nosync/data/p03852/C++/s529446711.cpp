#include <iostream>

using namespace std;

int main(void){
    char c;
    cin >> c;
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 6; i++){
        if(i == 5)  cout << "consonant"<< endl;
        else if(c == v[i]){
            cout << "vowel"<< endl;
            break;
        }
    }
    return 0;
}
