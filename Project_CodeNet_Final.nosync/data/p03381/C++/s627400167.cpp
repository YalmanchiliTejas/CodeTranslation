#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define fi first
#define se second
#define lson l,mid,o<<1
#define rson mid+1,r,o<<1|1
#define fio ios::sync_with_stdio(false);cin.tie(0)
#define I64 ll
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> P;
typedef pair<P, int> PII;
typedef pair<LL, int> PIII;
const LL INF = 0x3f3f3f3f;
const int N = 5e5 + 10;
const int M = 1e5 + 10;
const LL mod = 998244353;
const double PI=acos(-1);
inline LL ab(LL x){return x < 0 ? -x : x;}
inline int mm(int x, int p){return x >= p ? x - p : x < 0 ? x + p : x;}

int num[N];
int v[N];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &num[i]), v[i] = num[i];
    sort(v + 1, v + n + 1);
    for(int i = 1; i <= n; ++i){
        if(num[i] <= v[n >> 1]) printf("%d\n", v[(n >> 1) + 1]);
        else    printf("%d\n", v[n >> 1]);
    }
    return 0;
}
/*
13
0 1 1 3 3 0 6 6 8 9 9 9
100
R 8 8
R 8 8
W 8
W 6
R 1 9
W 6
R
*/
