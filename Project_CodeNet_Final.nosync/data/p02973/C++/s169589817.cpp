/*
    _____
  .'|||||'.
 /  >   <  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
    |||||
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
int n,a[200010];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    multiset<int,greater<int>> s;
    for (int i=1;i<=n;i++)
    {
        multiset<int>::iterator it=s.upper_bound(a[i]);
        if (it!=s.end()) s.erase(it);
        s.insert(a[i]);
    }
    printf("%d\n",s.size());
    return(0);
}
