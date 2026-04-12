#include<bits/stdc++.h>
using namespace std;

long long int N, a[200202], b[200202];

int main(){
    scanf("%lld", &N);
    for(int i = 0; i < N; ++i){
        scanf("%lld", a + i);
        b[i] = a[i];
    }
    sort(b, b + N);
    for(int i = 0; i < N; ++i){
        printf("%lld\n", (a[i] < b[N / 2]) ? b[N / 2] : b[N / 2 - 1]);
    }
    return 0;
}