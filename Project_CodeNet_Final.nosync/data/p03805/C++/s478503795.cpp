#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <limits>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define PI (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=((n)-1);i>=0;i--)
#define rrep(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int g[10][10];
int tot = 0,n;
void doVis(int node,int mask)
{
    int nwMask = (mask | (1<<node));
    if(nwMask == ((1<<n) - 1))
    {
        tot++;
        return;
    }
    Rep(i,n)
    {
        if(g[node][i] && ((1<<i)&nwMask) == 0)
        {
            doVis(i, nwMask);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin >> n;
    int m;
    cin >> m;
    Rep(i,m)
    {
        int a,b;
        cin >> a >> b;
        g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
    }
    doVis(0,0);
    cout << tot << endl;
    return 0;
}

