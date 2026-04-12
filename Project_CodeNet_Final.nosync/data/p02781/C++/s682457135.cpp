#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int N_size;
char N[110];
int K;

ll rec(int i, int p, bool high) {
    if(i >= N_size) return (p >= K) ? 1LL : 0LL;
    if(p >= K) return 1LL;
    ll k = N[i] - '0';
    if(high){
        ll res = 0LL;
        res += rec(i+1, p, (k > 0 ? false : true));
        if(k > 1) res += (k-1LL)*rec(i+1, p+1, false);
        if(k > 0) res += rec(i+1, p+1, true);
        return res;
    }
    
    return rec(i+1, p, false) + 9*rec(i+1, p+1, false);
}

void solve(){
    ll res = 0;
    int k = N[0] - '0';
    res = rec(1, 0, false) + (k-1)*rec(1, 1, false) + rec(1, 1, true);
    printf("%lld\n", res);
}

int main()
{
    scanf("%s", N);
    scanf("%d", &K);
    N_size = strlen(N);
    solve();
    return 0;
}