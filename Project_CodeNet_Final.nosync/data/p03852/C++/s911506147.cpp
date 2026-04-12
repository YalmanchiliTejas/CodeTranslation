#include <bits/stdc++.h>
using namespace std;
int main(void){
    char c = ' ';
    string vowel = "aiueo";
    string ans ="consonant";
    cin >> c;
    for (int i=0; i< 5; i++){
        if (c==vowel[i]){
            ans = "vowel";
            break;
        }
    }
    cout << ans;
}