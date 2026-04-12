#include <iostream>
#include <assert.h>
#include <algorithm>
#include <string>

int64_t calc_num_putty(int64_t level, int64_t* length, int64_t* numP, int64_t offset){
    if(level == 1){
        if(offset == 0) return 0;
        else if(offset == 1) return 0;
        else if(offset == 2) return 1;
        else if(offset == 3) return 2;
        else return 3;
    }

    int64_t sum = 0;
    if(offset > length[level] / 2 + 1){
        sum = (numP[level] - 1) / 2 + 1;
        sum += calc_num_putty(level-1, length, numP, offset - length[level] / 2 - 1);
        return sum;
    }
    else if(offset == length[level] / 2 + 1){
        sum = (numP[level] - 1) / 2 + 1;
        return sum;
    }
    else{
        sum = calc_num_putty(level-1, length, numP, offset - 1);
        return sum;
    }
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int64_t N, X;
    std::cin >> N >> X;
    int64_t length[N+1];
    length[0] = 1;
    int64_t numP[N+1];
    numP[0] = 1;
    for(int32_t i = 1; i <= N; i++){
        length[i] = length[i-1] * 2 + 3;
        numP[i] = numP[i-1] * 2 + 1;
    }
    int64_t res = 0;
    res = calc_num_putty(N, length, numP, X);

    std::cout << res;

}
