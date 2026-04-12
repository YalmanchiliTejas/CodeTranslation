#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    cin >> c;
    
    if((c == 'a') || (c == 'i') || (c == 'u') || (c == 'e') || (c == 'o')){
        //母音のとき
        cout << "vowel" << endl;
    }else{
        //子音のとき
        cout << "consonant" << endl;
    }
}