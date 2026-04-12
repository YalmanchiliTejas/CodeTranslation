#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    char c[10];
    scanf("%s", c);
    int l = strlen(c);
    
    // 2. 判定.
    bool ok = false;
    for(int i = 0; i < l - 1; i++){
        if(c[i] == 'A' && c[i + 1] == 'C') ok = true;
    }
    
    // 3. 出力.
    if(ok) printf("%s\n", "Yes");
    else   printf("%s\n", "No");
    return 0;
    
}