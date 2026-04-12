#include <bits/stdc++.h>
using namespace std;
 
int main() {
    char c;
    cin >> c;
    
    string vowel = "aiueo";
    
    int i;
    for(i = 0; i < vowel.size() ; i++){
        if(vowel.at(i) == c){
            cout << "vowel" << endl;
            break;
        }
        else{
            if(i == vowel.size() -1)   cout << "consonant" << endl;
            continue;
        }
    }
    
}