#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef uint64_t u64;
typedef int64_t i64;

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
    const u64 n = read_int();
    const u64 w = read_int();
    const u64 mod = 998244353;
    u64 *dp = ALLOC (w + 1, u64);
    u64 ans = 0;
    u64 batch = 34;
    for (u64 i = 0; i < n; i += batch) {
        for (u64 j = i; j < i + batch && j < n; ++j) {
            const u64 a = read_int();
            dp[0] += 1;
            u64 *x = dp + w;
            u64 *y = dp + w - a;
            for (u64 i = a; i <= w; ++i) {
                *x += *y;
                --x;
                --y;
            }
            ans += dp[w] % mod;
        }
        u64 *v = dp;
        for (u64 i = 0; i <= w; ++i) {
            *v %= mod;
            ++v;
        }
    }
    printf ("%" PRIu64 "\n", ans % mod);
}

int main (void) {
    run();
    return 0;
}
