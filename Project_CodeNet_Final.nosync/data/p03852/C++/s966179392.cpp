#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    bool check=false;
    cin >> c;
    for(char vowel:{'a', 'i', 'u', 'e', 'o'}){
        if(c==vowel){
            check=true;
            }
    }
    if(check==true){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
}


