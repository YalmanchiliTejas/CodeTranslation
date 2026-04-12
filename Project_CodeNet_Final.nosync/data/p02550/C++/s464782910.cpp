#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <bitset>
#include <complex>
#define ll long long
#define INF 1000000000000000001
#define MOD 1000000007
using namespace std;

int main(){
    ll N,X,M;
    cin >> N>>X>>M;
    
    if(X==0){
        cout<<0<<endl;
        return 0;
    }
    
    if(N<=M){
        ll ans = 0;
        ll x=X;
        for(int i=0; i<N; i++){
            ans += x;
            x = (x*x)%M;
        }
        cout<<ans<<endl;
        return 0;
    }
    
    ll exist[100000]={};    // 何番めで出たか
    for(int i=0; i<100000; i++){
        exist[i]=-1;
    }
    ll temp[100001]={}; // i版めばでのわ
    ll x=X;
    
    exist[x]=0;
    temp[0]=x;
    
    for(int i=1; i<=M; i++){
        x = (x*x)%M;
        
        if(x==0){
            cout<<temp[i-1]<<endl;
            return 0;
        }
        
        if(exist[x]!=-1){
            // かぶったとき
            ll ans = 0;
            if(exist[x]==0){
                // 周期i
                ans += temp[i-1]*(N/i);
                if(N%i != 0){
                    ans += temp[N%i-1];
                }
            }else{
                temp[i]=temp[i-1]+x;
                
                
                ans += temp[exist[x]-1];
                ll num = i - exist[x];
                ll t = temp[i-1] - temp[exist[x]-1];
 
                N -= exist[x];
                ans += t*(N/num);
                if(N%num>0){
                    ans +=  temp[exist[x]+(N%num)-1] - temp[exist[x]-1];
                }
            }
            
            cout<<ans<<endl;
            return 0;
        }
        
        
        exist[x]=i;
        temp[i]=temp[i-1]+x;

    }
    
    cout<<temp[M-1]<<endl;
    return 0;
}
