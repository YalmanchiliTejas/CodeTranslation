#include<iostream>
#include<vector>
#include<string>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
    }
    int maxh = h[0];
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(maxh <= h[i]){
            cnt++;
            maxh = h[i];
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
