#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    long long N, ans = 0, a;
    long long a_2, sum = 0, sum_2 = 0;
    std::cin >> N;
    for(long long i = 0; i < N; i++){
        std::cin >> a;
        a_2 = (a*a)%1000000007;
        sum = (sum + a)%1000000007;
        sum_2 = (sum_2 + a_2)%1000000007;
        //std::cout << sum << " " << sum_2 << "\n";
    }

    ans = ((sum * sum)%1000000007 - sum_2);
    ans = ans%1000000007;
    ans = (ans * 500000004)%1000000007;

    if(ans < 0){
         ans = 1000000007 + ans;
    }

    std::cout << ans;
}
