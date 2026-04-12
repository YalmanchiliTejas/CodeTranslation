#include <iostream>

using namespace std;

int main() {
    char c;
    cin >> c;
    bool flag=false;
    char vs[5]={'a', 'e', 'i', 'o', 'u'};
    for(int i=0; i<5; i++) {
        if(vs[i]==c) {
            flag=true;
            break;
        }
    }
    if(flag) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }



    return 0;
    
    
}