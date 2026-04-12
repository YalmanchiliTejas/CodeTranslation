#include <iostream>

int main(){
    int N;
    std::cin >> N;

    int H[N];
    for(int i = 0; i < N; i++){
        std::cin >> H[i];
    }

    int ans = 1;
    int highest = H[0];
    for(int i = 1; i < N; i++){
        if(highest <= H[i]){
            highest = H[i];
            ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}