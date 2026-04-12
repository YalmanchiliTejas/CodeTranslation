#include <iostream>

int main()
{
    long long N, K;
    std::cin >> N >> K;

    if(K == 0){
        std::cout << N*N << std::endl; return 0;
    }
    
    long long count = 0;
    for(int i=K+1; i<=N; i++){
        count += (N / i) * (i - K);
        count += (N % i) >= K ? (N % i) - K + 1 : 0;
        // printf("%d %lld\n", i, count);
    }

    std::cout << count << std::endl;
}