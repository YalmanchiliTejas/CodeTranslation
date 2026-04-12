#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <climits>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <random>
#include <set>
#include <queue>
#include <complex>
#include <stack>
#include <numeric>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
using namespace std;
std::vector<bool> IsPrime;



void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    }
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない
    
    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}
inline void InitRand()
{
    srand((unsigned int)time(NULL));
}

int main() {
    //InitRand();
    cin.tie(0);
    ios::sync_with_stdio(false);
    //std::ifstream in("input.txt");std::cin.rdbuf(in.rdbuf());
    int n,k;
    cin>>n>>k;
    long long ans=0;
    long long t=0;
    int r=0;
    if(k==0){
        
            for(int b=k+1;b<=n;++b){
                r=n%b;
                if(r<k){t=(n-k)/b+1;ans+=t*(b-k);}else{
                    t=(n-k)/b+1;ans+=t*(r-k+1);ans+=(t-1)*(b-r-1);
                }
            
           
        }
        ans=ans-n;
        cout<<ans<<endl;
            }else{
            for(int b=k+1;b<=n;++b){
                r=n%b;
                if(r<k){t=(n-k)/b+1;ans+=t*(b-k);}else{
                    t=(n-k)/b+1;ans+=t*(r-k+1);ans+=(t-1)*(b-r-1);
        }
            }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}
