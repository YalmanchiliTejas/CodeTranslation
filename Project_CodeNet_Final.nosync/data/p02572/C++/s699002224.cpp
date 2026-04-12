#include <bits/stdc++.h>

int modnum = 1e9+7;

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    long long cur_sum = 0;
    long long ans = 0;
    for(int i=0; i<N; i++){
        ans = (ans + (cur_sum * A[i]) % modnum) % modnum;
        cur_sum = (cur_sum + A[i]) % modnum;
    }
    
    std::cout << ans << std::endl;
    
    
    return 0;
    
}
