#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 3005;
ll mod = 998244353, ans;
int n, a[MM], s;
ll dpl[MM], dpr[MM], psl[MM], psr[MM];

void addmod(ll &x, ll y){
    x += y;
    if(x >= mod)
        x -= mod;
}

void go(int l, int r){
    if(l == r){
        if(a[l] == s)
            addmod(ans, 1);
        return;
    }
    int m = (l+r)/2;
//    print(l, m, r);
    for(int j = 0; j < MM; j++)
        dpl[j] = psl[j] = dpr[j] = psr[j] = 0;
    dpl[0] = dpr[0] = 1;
    for(int i = m; i >= l; i--){
        for(int j = 3000; j >= 0; j--){
            if(j >= a[i]){
                addmod(dpl[j], dpl[j-a[i]]);
            }
            addmod(psl[j], dpl[j]);
        }
    }
    for(int i = m+1; i <= r; i++){
        for(int j = 3000; j >= 0; j--){
            if(j >= a[i]){
                addmod(dpr[j], dpr[j-a[i]]);
            }
            addmod(psr[j], dpr[j]);
        }
    }
    for(int i = 0; i <= s; i++){
//        print(i, s-i, psl[i], psr[s-i]);
        ans = (ans + psl[i]*psr[s-i]) % mod;
    }
    go(l, m);
    go(m+1, r);
}

int main(){
    scan(n, s);
    for(int i = 0; i < n; i++){
        scan(a[i]);
    }
    go(0, n-1);
    print(ans);
    
    return 0;
}