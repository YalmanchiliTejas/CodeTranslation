#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    
    // 1. 入力情報.
    LL K, A, B, ans = 0;
    scanf("%lld %lld %lld", &K, &A, &B);
    
    // 2. 皆伝になるには？
    if(K <= A){
        puts("1");
    }else{
        if(A - B <= 0){
            puts("-1");
        }else{
            ans = (K - A) / (A - B);
            if(ans * (A - B) == (K - A)) printf("%lld\n", 2 * ans + 1);
            else                         printf("%lld\n", 2 * ans + 3);
        }
    }
    return 0;
    
}