#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include<climits>
#include <string>
#include <map>
#include <set>
#include <list>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;

/////////////////////////////////////////////////////
#define pll pair<ll,ll>

ll N,X;

ll i,bp[55], p[55],ans;

int main(){
    scanf("%lld%lld", &N, &X);
    bp[0] = 1;
    p[0] = 1;
    fornum(i,0,N){
        bp[i + 1] = 3 + bp[i] * 2;
        p[i + 1] = 1 + p[i] * 2;
        //printf("%lld,%lld\n", bp[i + 1], p[i+1]);
    }
    ll x=0;
    for (i = N; i >= 0;i--){
        ll sx = X - x;
         //printf("%lld,%lld,%lld %lld %lld\n", i, x, sx,X,bp[i-1]);
        
        if(i==0){
            ans += 1;
            break;
        }
        if(sx==1){
            break;
        }else if(sx<=bp[i-1]+1){
            x = x + 1;
        }else if(sx==bp[i-1]+2){
            ans += p[i - 1]+1;
            break;
        }else if(sx<=bp[i-1]*2+2){
            ans += p[i - 1]+1;
            x=x +bp[i-1]+ 2;
        }else{
            ans += p[i];
            break;
        }
    }
        //dnf(N, 0);
    printf("%lld", ans);

    return 0;
}