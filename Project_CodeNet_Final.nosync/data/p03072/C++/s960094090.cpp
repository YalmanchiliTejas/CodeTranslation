/*
    1) Notice the range of data;
    2) while(scanf) format need to init;
    3) Enough maxn;
    4) delete the freopen;
    5) remember to read this before submit;
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int gcd(int a,int b){if (b == 0) return a; return gcd(b , a%b);}
int lcm(int a, int b){ return a/gcd(a,b)*b;}
inline int read(){
    int f = 1, x = 0;char ch = getchar();
    while (ch > '9' || ch < '0'){if (ch == '-')f = -f;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
const int maxn = 1e5 + 10;
int a[maxn];
int main(){
    int n = read();
    int maxx = 0,ans = 0;
    for(int i=1; i<=n; i++){
        a[i] = read();
        if (a[i] >= maxx){
            ans++;
            maxx = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}