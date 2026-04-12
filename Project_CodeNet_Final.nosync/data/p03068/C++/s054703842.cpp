#include <cstdio>
#include <string>

int main()
{
    int N, K;
    scanf("%d", &N);
    char S[N+1];
    scanf("%s", S);
    scanf("%d", &K);
    for(int i=0; i<N; i++){
        if(S[i] != S[K-1])
            S[i] = '*';
    }
    printf("%s\n", S);
    return 0;
}
