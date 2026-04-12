#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    char  c;
    cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
}
