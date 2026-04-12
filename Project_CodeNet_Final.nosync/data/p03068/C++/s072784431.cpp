#include <iostream>

int main() {
    int N,K;
    char S[10],temp;

    scanf("%d",&N);
    scanf("%s",&S);
    scanf("%d",&K);
    temp = S[K-1];

    for(int i = 0; i < N; i++){
        if(S[i] != temp){
            S[i] = '*';
        }
    }

    printf("%s",S);

    return 0;
}