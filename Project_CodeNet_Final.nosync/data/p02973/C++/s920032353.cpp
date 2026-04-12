#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
ll N, A[101010];
ll cl[101010];
ll i,j,ans;

bool solve(ll a){
    ll i, j;
    fornum(i,0,a+1){
        cl[i] = -1;
    }
    
    fornum(i,0,N){
        ll l = 0, r = a;
        while(l<r){
            ll c = (l + r) / 2;
            if(cl[c]<A[i]){
                r = c;
            }else{
                l = c+1;
            }
        }
        if(l==a){
            return false;
        }
        cl[l] = A[i];
    }
    return true;
}

int main(){
    scanf("%lld", &N);
    fornum(i,0,N){
        scanf("%lld", &A[i]);
    }
    ll l = 1, r = N;
    while(l<r){
        ll c = (l + r) / 2;
        if(solve(c)){
            r = c;
        }else{
            l = c + 1;
        }
    }
    printf("%lld", l);

    return 0;
}