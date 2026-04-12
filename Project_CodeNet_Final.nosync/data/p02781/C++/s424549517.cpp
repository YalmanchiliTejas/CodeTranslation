#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
char N[200];
ll K;
ll i,j,k;
ll calc(ll ii,ll kk,bool c,ll d){
    if(kk==0){
        return d;
    }
    ll ret = 0;
    for (ll i = ii; N[i];++i){
        if(c){
            if(N[i]=='0')
                continue;
            ret += calc(i + 1, kk - 1, false, d * (N[i] - '1'));
            ret += calc(i + 1, kk - 1, true, d);
            c = false;
        }else{
            ret += calc(i+1, kk - 1, false, d*9);
        }
    }
    return ret;
}
int main(){
    scanf("%s%lld", N,&K);
    printf("%lld", calc(0, K, true, 1));
    return 0;
}