#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = (int) 1e9+7;

void __print() {cerr << "]\n";}

template<typename T, typename... V>
void __print(T t, V... v)
{ cerr << t; if(sizeof...(v)) cerr << ", "; __print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = [", __print(x)
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    u64 n, x, m;
    u64 sum[200000];
    int fl[200000];
    scanf("%llu%llu%llu", &n, &x, &m);
    memset(sum, 0, sizeof sum);
    memset(fl, 0, sizeof fl);
    sum[1] = x;
    fl[x] = 1;
    u64 ans = x;
    for(i64 i = 2; i <= n; i++) {
        x *= x;
        x %= m;
        // if(x == 0) break;
        if(fl[x]) {
            ans = sum[fl[x]-1];
            i64 f = i - fl[x];
            i64 k = ((n-fl[x]+1)/f);
            i64 l = ((n-fl[x]+1)%f);
            ans += (sum[i-1]-sum[fl[x]-1])*k;
            ans += sum[fl[x]+l-1] - sum[fl[x]-1];
            break;
        } else {
            fl[x] = i;
            sum[i] = x + sum[i-1];
            ans = sum[i];
        }
    }
    printf("%llu\n", ans);
}
