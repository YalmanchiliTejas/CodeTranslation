#include<iostream>
#include<vector>

int main (){
    std::cin.tie(0); 
    std::ios::sync_with_stdio(false);
    int N;std::cin >> N;
    long long sumA=0,ans=0;
    std::vector<long long> A(N,0);for (int i=0;i<N;++i){std::cin >> A[i];sumA+=A[i]; }
    long long modN=1000000007;

    for (int i=0;i<N-1;++i){
        sumA -= A[i];
        ans += A[i] * (sumA % modN);
        ans %= modN;
    }
    std::cout << ans;
    return 0 ;
}
