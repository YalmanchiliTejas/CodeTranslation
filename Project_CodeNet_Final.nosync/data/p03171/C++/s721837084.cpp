#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define LIM 3000


LL sum, csum[LIM+5], dp[LIM+5][LIM+5], ara[LIM+5];
bool vis[LIM+5][LIM+5];

LL f(int lft, int rht){
    if(lft == rht) return ara[lft];
    if(lft > rht) return 0;
    if(vis[lft][rht]) return dp[lft][rht];
    vis[lft][rht] = 1;
    LL takeLeft = ara[lft] + (csum[rht]-csum[lft]) - f(lft+1, rht);
    LL takeRight = ara[rht] + (csum[rht-1]-csum[lft-1]) - f(lft, rht-1);
    return dp[lft][rht] = max(takeLeft, takeRight);
}

int main(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++) cin>>ara[i];
    for(int i = 1; i <= n; i++){
        csum[i] = csum[i-1] + ara[i];
        sum += ara[i];
    }

    LL res = f(1, n);
    cout<<(res-(sum-res))<<'\n';
    //cout<<sum<<'\n';
    //cout<<res<<'\n';
}


