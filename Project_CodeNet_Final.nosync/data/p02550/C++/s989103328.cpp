#include<bits/stdc++.h>

#define ll long long
#define rep(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

#define fi first
#define se second
#define all(A) A.begin(),A.end()

using namespace std;

/////////////////////////////////////////////////////

ll N, X, M;
ll mk[101010];
ll mk2[101010];
ll i, j, k;

int main(){
    scanf("%lld%lld%lld", &N, &X, &M);
    i = 1;
    j = X;
    while(mk[j]==0){
        mk[j] = i;
        mk2[i-1] = j;
        ++i;
        j = j * j % M;
    }
    
    
    ll a = mk[j]-1;
    ll b = i-1;

    //rep(i,0,b+2){
    //    printf("%lld,", mk2[i]);
    //}
    //printf("%lld,%lld\n", a, b);

    ll ans = 0;
    if(N<a){
        rep(i,0,N){
            ans += mk2[i];
        }
    }else{
        rep(i,0,a){
            ans += mk2[i];
            //printf(" %lld:%lld,", mk2[i],ans);
        }
        ll ansp=0;
        rep(i,a,b){
            ansp += mk2[i];
        }
        N -= a;
        ll d = N / (b - a);
        ll m = N % (b - a);
        //printf("\n%lld,%lld,%lld,%lld\n",N, d, m,ansp);
        ans += d * ansp;
        rep(i,0,m){
            ans += mk2[i + a];
            //printf(" %lld:%lld,", mk2[i + a],ans);
        }
    }
    printf("%lld\n", ans);

    return 0;
}