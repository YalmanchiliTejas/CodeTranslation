
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int N =100303;
const LL inf = (LL) 1<<40;
#define mod 1000000007
//437001103351396 10int

int f[N];
struct node
{
    int id,val;
}a[N],b[N];

struct edge
{
    int x,y,val;
}c[N*2];

int find(int x)
{
    if (f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

int cmp(node a,node b)
{
    return a.val<b.val;
}
int cmp2(edge a,edge b)
{
    return a.val<b.val;
}

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i].id=i;
        a[i].val=x;
        b[i].id=i;
        b[i].val=y;
    }


    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;i++) f[i]=i;

    long long ans = 0;

    int t=0;
    for (int i=2;i<=n;i++)
    {
        t++;
        c[t].x=a[i-1].id;
        c[t].y=a[i].id;
        c[t].val=abs(a[i].val-a[i-1].val);
    }

    for (int i=2;i<=n;i++)
    {
        t++;
        c[t].x=b[i-1].id;
        c[t].y=b[i].id;
        c[t].val=abs(b[i].val-b[i-1].val);
    }

    sort(c+1,c+t+1,cmp2);
    for (int i=1;i<=t;i++)
    {
        int x=find(c[i].x);
        int y=find(c[i].y);
        if (x!=y)
        {
            ans += c[i].val;
            f[x]=y;
        }
    }
    cout<<ans<<endl;
    return 0;
}
