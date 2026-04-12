#include<vector>
#include<iostream>
int main(){
    int N;
    std::cin>>N;
    std::vector<unsigned long long>A(N);
    std::vector<unsigned long long>sum(N);
    for(int i=0;i<N;++i){
        std::cin>>A[i];
    }
    for(int i=N-1;i>=0;--i){
        if(i==N-1){
            sum[i]=A[i];
        }
        else{
            sum[i]=(sum[i+1]+A[i])%1000000007;
        }
    }
    unsigned long long ans=0;
    for(int i=0;i<N-1;++i){
        ans=(ans+sum[i+1]*A[i])%1000000007;
    }
    std::cout<<ans<<std::endl;
}