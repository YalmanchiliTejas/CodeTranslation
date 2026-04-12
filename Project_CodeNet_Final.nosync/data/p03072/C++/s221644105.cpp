#include <iostream>
#include <vector>

int main(){
    int N, ans = 1;
    std::cin >> N;
    std::vector<int> H(N);
    for(auto i = 0; i < N; i++){
        std::cin >> H.at(i);
    }

    int max = H.at(0);
    for(auto i = 1; i < N; i++){
        if(max <= H.at(i)){
            ans++;
            max = H.at(i);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
