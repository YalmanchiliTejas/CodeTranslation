#include <iostream>
#include <string>
#include <math.h>
    using namespace std;

    int main() {
        string s="aeiuo";
        char c;
        cin>>c;
        for (int i = 0; i <s.size() ; ++i) {
            if(c==s[i]){
            cout<<"vowel";
                return 0;
            }
        }
        cout<<"consonant";}