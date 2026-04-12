#include<bits/stdc++.h>

using namespace std;
const int MAX=3000+3;
typedef long long ll;
int N;
ll a[MAX], dp[MAX][MAX];

//ll solve(int p, int q, int t=0) {
//  if(p>q) return 0;
//
//  if(dp[p][q] != -1) {
//    return dp[p][q];
//  }
//  if(t) {
//    return dp[p][q] = min(solve(p+1, q, 0) - a[p], solve(p, q-1, 0) - a[q]);
//  } else {
//    return dp[p][q] = max(solve(p+1, q, 1) + a[p], solve(p, q-1, 1) + a[q]);
//  }
//}

ll solve(int l, int r, int t){

    if(l > r) return 0;
    ll &ret=dp[l][r];
    if(ret!=-1) return ret;

    if(t){
        ret=min(solve(l+1, r, 0)-a[l], solve(l, r-1, 0)-a[r]);
    } else {
        ret=max(solve(l+1, r, 1)+a[l], solve(l, r-1, 1)+a[r]);
    }

    return ret;

}


int main(){
    scanf("%d",&N);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<N;i++) scanf("%lld",&a[i]);
    printf("%lld\n",solve(0, N-1, 0));
    return 0;
}
