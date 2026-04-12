#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
int n,k;
int main(){
    cin >> n>> k;
    ll ans=0;
    for(int b=max(1,k+1);b<=n;b++){
        for(int a=1;a<=n;){
            if(a%b>=k){
                ans+=b-(a%b);
                a+=b-(a%b);
                if(a>n){
                    ans-=(a-n-1);
                }
            }else{
                a+=(k-(a%b));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}