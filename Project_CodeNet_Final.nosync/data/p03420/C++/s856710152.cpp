#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#define INF 0X3F3F3F3F
#define N 1005
#define M 200005
#define LL long long
#define ULL unsigned long long
#define FF(i, a, b) for(int i = a; i <= b; ++i)
#define RR(i, a, b) for(int i = a; i >= b; --i)
#define FJ(i, a, b) for(int i = a; i < b; ++i)
#define SC(x) scanf("%d", &x)
#define SCC(x, y) scanf("%d%d", &x, &y)
#define SCCC(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define SS(x) scanf("%s", x)
#define PR(x) printf("%d\n", x)
#define CL(a, x) memset(a, x, sizeof(a))
#define _P fd[rt]
#define _L fd[rt << 1]
#define _R fd[rt << 1 | 1]
#define MID int mid = ((l + r) >> 1)
#define lson rt<<1 ,l, mid
#define rson rt<<1 | 1, mid + 1, r
#define VI vector<int>
#define db double
#define PII pair<int, int>
#define PLL pair<unsigned long long, unsigned long long>
#define MP make_pair
#define PB push_back
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
using namespace std;
int n, k;
int main(){
    // IN;
    SCC(n, k);
    if(k == 0){
        cout << 1LL * n * n << endl;
    }else {
        LL ans = 0;
        FF(b, k + 1, n){
            ans += 1LL * (b - k) * (n / b) + (max(0, n % b - k + 1));
        }
        cout << ans << endl;
    }
    return 0;
}
