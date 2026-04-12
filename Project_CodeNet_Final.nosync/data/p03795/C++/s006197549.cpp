#include<iostream>

int main(){
    int N;
    std::cin >> N;
    int res = N * 800;
    res -= (N / 15) * 200;
    std::cout << res << std::endl;
    return 0;
}
