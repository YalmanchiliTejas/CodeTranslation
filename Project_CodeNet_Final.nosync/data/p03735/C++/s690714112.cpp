#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef pair<int, int> pii;
typedef double lf;
typedef long long ll;
#define int long long
const int inf=0x3f3f3f3f, mod=1000000007;
pii a[200200];

inline int read()
{
    int x=0,f=1; char ch=getchar();
    for (; ch<'0' || ch>'9'; ch=getchar()) if (ch=='-') f=-1;
    for (; ch>='0' && ch<='9'; ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}

multiset<int> A, B;
int calc(){return (*A.rbegin()-*A.begin())*(*B.rbegin()-*B.begin());}

signed main()
{
    int n=read();
    for (int i=1; i<=n; i++) 
    {
        int x=read(), y=read(); if (x>y) swap(x, y);
        A.insert(x); B.insert(y);
        a[i].first=x; a[i].second=y;
    }
    int ans=calc();
    sort(a+1, a+n+1);
    for (int i=1; i<=n; i++)
    {
        int x=a[i].first, y=a[i].second;
        A.erase(A.find(x)); A.insert(y);
        B.erase(B.find(y)); B.insert(x);
        ans=min(ans, calc());
    }
    printf("%lld\n",ans);
    return 0;
}
