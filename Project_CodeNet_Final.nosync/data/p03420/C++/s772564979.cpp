#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#define INF 100000000
#define MOD 1000000007
using namespace std;



int main(){
    long long M;
    cin >> M;
    
    long long K;
    cin >> K;
    
    if(K==0){
        cout<<M*M<<endl;
        return 0;
    }
    
    long long ans=0;
    
    for(long long b=K+1; b<=M; b++){
        long long N=M;
        ans+=(b-K)*(N/b);
        N%=b;
        
        if(K<=N){
            ans+=N-K+1;
        }
      
    }
    
    cout<<ans<<endl;
    return 0;
}
