#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <tuple>
#define ll long long
using namespace std;


vector<int> divs[111111];

ll Sumit(ll N, ll low,ll high) {
    
    // N/low+N/low+1+....
    
    ll curr = low;
    
    ll ans = 0;
    
    while(curr <= high) {
        
        ll val = N/curr;
        
        if (val == 0)
            break;
        
        // N/x >= val
        
        // x <= N/val
        
        ll up = min(high,N/val);
        
        
        ans += (up-curr+1)*val;
        
        curr = up+1;
        
    }
    
    return ans;
    
    
    
}


ll BruteForce(ll N,ll K) {
    int ans=0;
    for(int a=1;a<=N;a++) {
        for(int b=1;b<=N;b++)
            if (a%b>=K)
                ans++;
    }
    return ans;
}

int main() {
    int N,K;
    cin>>N>>K;
    
    // (a%b) >= K
    // a = b*x+K
    // where b >= K+1
    ll ans = 0;
    
    for(int k=K;k<=N;k++) {
        
        // b >= k+1
        
        // b*x+k
        
        
        // (k+1)*x+k,(k+2)*x+k
        // k,(2*k+1),(2*k+2),...,
        
        // x=0,1,...,(N-k)/b
        
        // (N-k)/b+1
        
        
        ans += N-k;
        
        
        ans += Sumit(N-k,k+1,N);
        
        
        //for(int b=k+1;b<=N;b++)
          //  ans += (N-k)/b;
        
        
        
        
        
        
    }
    
    cout << ans-(K==0?N:0) << endl;
    //cout << BruteForce(N,K) << endl;

}