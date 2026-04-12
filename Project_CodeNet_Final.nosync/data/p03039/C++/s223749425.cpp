#include <iostream>
#include <vector>

constexpr unsigned long int m = 1000000000ul + 7ul; //a prime modulus

unsigned long int getModInv(const unsigned long int a){
    constexpr unsigned long int p = m-2ul;
    unsigned long int mod = 1ul;
    for(int j=63; j>=0; --j){
        mod = mod*mod % m;
        if( ((p>>j)&1ul)==1ul ){
            mod = mod*a % m;
        }
    }
    return mod;
}

int main(int argc, char *argv[]){
    unsigned long int N,M,K;
    std::cin >> N >> M >> K;

    unsigned long int C=(N*M*( N*(M*M - 1ul) + M*(N*N - 1ul) ))/6ul;
    C %= m;
    unsigned long int numerator=M*N-2ul, denominator=K-2ul;
    while(denominator > 0ul){
        C *= numerator;
        C %= m;
        C *= getModInv(denominator);
        C %= m;
        --numerator;
        --denominator;
    }

    std::cout << C << std::endl;

    return 0;
}
