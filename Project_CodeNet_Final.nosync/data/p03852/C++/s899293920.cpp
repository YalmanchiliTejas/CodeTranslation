#include <iostream>
using namespace std;
int main(){
    char x;
    cin >> x;
    bool vowl = false;
    char vowel[5] = {'a' , 'e' , 'i' , 'o' , 'u'};
    for (int i = 0 ; i < 5 ; i++){
        if (x == vowel[i]) vowl = true;
    }
    if (vowl) cout << "vowel";
    else cout << "consonant";
    return 0;
}