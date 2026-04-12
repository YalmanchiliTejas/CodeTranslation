#include <iostream>
#include <vector>

int main()
{
    int N;
    long long X;
    std::cin >> N >> X;

    std::vector<long long> height(1, 1), patty(1, 1);
    for(int i=1; i<=N; i++){
        height.push_back(2 * height.back() + 3);
        patty.push_back(2 * patty.back() + 1);
    }

    long long sum = 0;
    for(int i=N; i>=0; i--){
        if(i == 0) sum += 1;
        if(X == 1) break;
        else if(X < height[i-1]+2) X -= 1;
        else if(X == height[i-1]+2){
            sum += patty[i-1] + 1; break;
        }
        else if(X < height[i]){
            sum += patty[i-1] + 1; X -= height[i-1]+2;
        }
        else{
            sum += patty[i]; break;
        }
    }
    // for(int i=0; i<=N; i++){
    //     std::cout << "i = " << i << ", height = " << height[i] << ", patty = " << patty[i] << std::endl;
    // }
    std::cout << sum << std::endl;
}