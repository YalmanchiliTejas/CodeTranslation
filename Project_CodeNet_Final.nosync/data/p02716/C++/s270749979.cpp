#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int n;
int a[200005];
ll mem[200005][3];
ll dp(int id, int remw){
    if (remw < 0) return -INF;
    if (id >= n+1) return remw == 0 ? 0 : -INF;
    if (mem[id][remw] != -1) return mem[id][remw];
    mem[id][remw] = max(dp(id+2,remw)+a[id],dp(id+1,remw-1));
    //printf("%d %d = %lld\n",id,remw,mem[id][remw]);
    return mem[id][remw];

}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    memset(mem,-1,sizeof(mem));
    if (n % 2 == 0){
        printf("%lld",dp(0,1));
    }
    else{
        printf("%lld",dp(0,2));
    }
}
