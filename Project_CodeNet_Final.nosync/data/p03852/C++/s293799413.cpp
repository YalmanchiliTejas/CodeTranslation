#include <iostream>
using namespace std;

int main(){
    string v = "aiueo";
    char c;
    cin >> c;
    int frg = 0;
    for(int i=0;i<5;i++){
        if(c==v[i])frg=1;
    }
    if(frg)cout << "vowel" << endl;
    else cout << "consonant" << endl;
}
