#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main(){
    ll n,k;
    std::cin >> n>>k;
    if(k==0){
        std::cout << n*n << std::endl;
        return 0;
    }
    
    // aをbで割ったあまりがk以上
    // a=b*s+r
    // あまりがk以上ということは少なくともbはkよりも大きい
    // b>k
    // a%b >= k;
    // bがとりうる値
    ll result = 0;
    for (int i = k+1; i <= n; i++) {
        // x*b-1 <= Nとなる最大のx
        ll mab = (n+1)/i;
        result += mab*(i-k);
        ll may = n-k-mab*i;
        // std::cout << i<<" "<<mab<<" "<<may << std::endl;
        
        if(may>=0){
            result+=may+1;
        }
        // std::cout <<mab<<" "<< i<<" "<<k<<" "<<may<<" "<<result << std::endl;
        // result += max((ll)0,may+1);
    }
    std::cout << result << std::endl;
    //     k,,,,,,,,,,,,b-1
    // a = b+k,b+k+1,,,,,2*b-1,
        // 2*b+k,,,,,,,,,3*b-1,
                        // x*b-1,
                        // < (x+1)*b-1.
            // x*b+k+y<=Nとなる最大のy
            // y<=n-k-x*b
            
    // 各bについて
        // i*b+k,,,(i+1)*b-1
        // 0,,,,b-1
        //  k,,b-1
        // b-k個
    // nという上限が来る
    
            
}
