#include <bits/stdc++.h>

#define DIV 1000000007

using namespace std;

long long int vet[212345], sm[212345];

int main(){
    int n;

    scanf(" %d", &n);

    for(int i = 0; i < n; i++)
        scanf(" %lld", vet + i);

    for(int i = n - 1; i >= 0; i--)
        sm[i] = (sm[i + 1] + vet[i]) % DIV;
    
    long long int resp = 0;
    for(int i = 0; i < n - 1; i++)
        resp = (resp + sm[i + 1] * vet[i]) % DIV;

    printf("%lld\n", resp);
    return 0;
}