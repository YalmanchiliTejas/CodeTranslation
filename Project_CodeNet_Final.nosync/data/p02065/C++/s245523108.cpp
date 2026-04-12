#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    int n, k; ll m;
    cin>>n>>k>>m;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    ll dp[222][1<<10]={};
    for(int i=2; i<=min(n+1, k+1); i++){
        dp[i][(1<<(i-1))-1]=1;
    }
    for(int i=2; i<2*n; i++){
        for(int j=1; j<(1<<k); j++){
            int t=i;
            int u=i, s=i;
            for(int l=k-1; l>=0; l--){
                if(j&(1<<l)){
                    if(u==i) u=i-1-l;
                    else if(t==i) t=i-1-l, s=t;
                    else s=i-1-l;
                }
            }
            for(int l=i+1; l<=t+k; l++){
                int q;
                if(t==i){
                    if(l==i+1 || i+1-u>k) continue;
                    q=((1<<(l-i-1))-1);
                }else{
                    q=(j^(1<<(i-1-u)))<<(l-i);
                    if(i+1-s>k) continue;
                    q+=((1<<(l-i-1))-1);
                }
                if(q>=(1<<k)) continue;
                (dp[l][q]+=dp[i][j])%=m;
            }
        }
    }
    ll ans=0;
    for(int i=0; i<k; i++){
        (ans+=dp[2*n][1<<i])%=m;
    }
    cout<<ans<<endl;
    return 0;
}
