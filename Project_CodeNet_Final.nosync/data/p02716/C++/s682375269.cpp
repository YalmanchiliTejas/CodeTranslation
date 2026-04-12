#include<iostream>
#include<numeric>
#include<vector>
#include<limits>
 
std::vector<std::int64_t> a;
std::vector<std::vector<std::int64_t>> memo;
const auto nil = std::numeric_limits<std::int64_t>::min();
 
std::int64_t solve(int n,int k){
    if(memo[n][k-n/2] != nil){
        return memo[n][k-n/2];
    }
    std::int64_t r ;
    {
        if(n==0 || k==0){
            r = 0;
        }
        else if(n == 1){
            r = a[0];
        }
        else if(n%2==1 && k == (n/2+1)){
            r = solve(n-2,k-1) + a[n-1];
        }
        else{
            auto r1 = solve(n-2,k-1) + a[n-1];
            auto r2 = solve(n-1,k);
            r = std::max(r1,r2);
        }
    }
 
    memo[n][k-n/2] = r;
    return r;
}
 
int main(){
    int n;
 
    std::cin>>n;
    for(int i=0;i<n;++i)
    {
        int tmp;
        std::cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n+2;++i){
        memo.push_back(std::vector<std::int64_t>(3,nil) );
    }
 
    std::cout<<solve(n,n/2);
    
    
}