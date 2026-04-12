#include<iostream>
#include<algorithm>
#include<vector>
#include <numeric>
using namespace std;

int main(int argc, char const *argv[]) {
int N,max,ans,tmp;
ans = 1;
    std::cin >> N>>max;
    for (size_t i = 0; i < N-1; i++) {
        std::cin >> tmp;
        if(max<=tmp){
            max=tmp;
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
