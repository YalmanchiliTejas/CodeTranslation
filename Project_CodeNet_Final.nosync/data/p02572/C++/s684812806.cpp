#include <iostream>

#define MOD 1000000007

int main(void) {
    int N;
    std::cin >> N;
    unsigned long long* reads = new unsigned long long[N];
    unsigned long long rightSum = 0;
    for(int i = 0; i < N; ++i){
        std::cin >> reads[i];
        rightSum += reads[i];
    }
    unsigned long long result = 0;
    for(int i = 0; i < N-1; ++i){
        rightSum -= reads[i];

        result = (result + reads[i] * (rightSum % MOD)) % MOD;
    }

    std::cout << result << std::endl;

    delete[] reads;
}