/// You just can't beat the person who never gives up
/// ICPC next year

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ,mod = 1e9+7 ;

int n ,a[N] ;
long long sum ,ans ;
bool Never_give_up(){
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",a+i);
    for(int i=n-1;i>=0;--i){
        ans = (ans + sum*a[i])%mod ;
        sum = (sum + a[i])%mod ;
    }
    cout << ans << endl ;
    return 0;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" ,"r" ,stdin);
    freopen("output.txt" ,"w" ,stdout);
#endif
    //std::ios::sync_with_stdio(0);
    //cin.tie(0) ,cout.tie(0);
    int t = 1 ;
    //scanf("%d",&t);
    while(t--){
        Never_give_up();
    }
    return 0;
}
