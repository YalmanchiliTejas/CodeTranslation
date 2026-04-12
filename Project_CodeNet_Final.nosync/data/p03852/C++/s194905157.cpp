#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    char c[11];
    scanf("%s", c);
    
    // 2. 母音か判定.
    bool ans = false;
    if(c[0] == 'a') ans = true;
    if(c[0] == 'e') ans = true;
    if(c[0] == 'i') ans = true;
    if(c[0] == 'o') ans = true;
    if(c[0] == 'u') ans = true;
    
    // 3. 出力.
    printf("%s\n", ans ? "vowel" : "consonant");
    return 0;
    
}