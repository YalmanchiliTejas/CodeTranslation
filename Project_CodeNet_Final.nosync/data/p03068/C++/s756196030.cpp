#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報取得.
    int N, K;
    char S[22];
    scanf("%d %s %d", &N, S, &K);
    
    // 2. S の K番目の文字と異なる文字全て '*' に置き換えて出力.
    for(int i = 0; i < N; i++){
        if(S[i] != S[K - 1]) printf("%c", '*');
        else                 printf("%c", S[i]);
    }
    printf("\n");
    return 0;
    
}