#include <iostream>

constexpr int MAX_TE = 1441, MAX_N = 100;

int main(){
    int ans = -1;
    int n, t, e;

    std::cin >> n >> t >> e;

    int begin = t - e, end = t + e;

    for(int i = 0; i < n; ++i){
        int x;
        std::cin >> x;

        int j = 0;
        if(ans == -1){
            while(true){
                ++j;
                int now_x = x * j;
            
                if(now_x >= begin && now_x <= end){
                    ans = i + 1;
                    break;
                }

                if(now_x > end)
                    break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}