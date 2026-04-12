#include <iostream>

// 1-indexed
long long costL[200020];
long long costLmax[200020];
long long costR[200020];
long long costRmax[200020];

int main(){
    int n;
    long long prev, ans = 0;
    std::cin >> n >> prev;
    for(int i = 1; i < n; i++){
        long long a;
        std::cin >> a;
        if(i % 2){
            int k = i/2+1; // k個目
            costL[k] = costL[k-1] + prev-a;
            ans += a;
        }else{
            costR[i/2] = a-prev;
        }
        prev = a;
    }
    for(int i = (n-1)/2; i > 0; i--){
        costR[i] += costR[i+1];
    }
    for(int i = 1; i <= n/2; i++){
        costLmax[i] = std::max(costL[i], costLmax[i-1]);
    }
    for(int i = (n-1)/2; i > 0; i--){
        costRmax[i] = std::max(costR[i], costRmax[i+1]);
    }
    if(n % 2){ // if odd
        long long M = costRmax[1];
        for(int i = 1; i <= n/2; i++){ // move left
//            M = std::max(M, costL[i] + costRmax[i+1]);
            if(M < costL[i] + costRmax[i+1]){
                M = costL[i] + costRmax[i+1];
            }
        }
        std::cout << M + ans << std::endl;
    }else{ // if even
        std::cout << ans + costLmax[n/2] << std::endl;
    }
}
