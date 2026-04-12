#include <cstdlib>
#include <cstdio>

int main() {
    char S[4];
    scanf("%s",S);
    printf(S[0]==S[1] && S[1]==S[2] ? "No" : "Yes");  
}
