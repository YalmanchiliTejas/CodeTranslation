#include <bits/stdc++.h>
using namespace std;


int main(void){
    char c;
    cin >> c;
    string jadge="aiueo";
    for(int i=0; i<5; i++){
        if(jadge[i]==c){
            cout << "vowel" << endl;
            return 0;
        }
    }

    cout << "consonant" << endl;
    return 0;
}