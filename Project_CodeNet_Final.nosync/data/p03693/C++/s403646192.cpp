#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

typedef long long LL;
#define lowbit(x) ((x)&(-x))
#define INF 0x3f3f3f3f
#define memset(a,b) memset(a,b,sizeof(a))
#define	GE() printf(">----------\n")
#define	IN() freopen("in.txt","r",stdin)
#define	OUT() freopen("out.txt","w",stdout)
const int mod=1000000007;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=100005;

int main()
{
    int r, g, b;
    while(~scanf("%d%d%d", &r, &g, &b)){
        int sum=r*100+g*10+b;
        printf("%s\n", sum%4?"NO":"YES");
    }
    return 0;
}

