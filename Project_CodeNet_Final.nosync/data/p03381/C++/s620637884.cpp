#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
//#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize (2)
#pragma G++ optimize (2)
#define mod 1000000007
#define PI acos(-1.0)
typedef long long ll;
typedef unsigned long long ull;
#define gcd __gcd
//const int INF=0x3f3f3f3f;
const ll INF=1000000000000000000;
//priority_queue<int, vector<int>, greater<int> >p;
int n;
int a[200005],b[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int x=n/2;
    for(int i=1;i<=n;i++)
        if(a[i]>b[x])printf("%d\n",b[x]);
        else printf("%d\n",b[x+1]);
    return 0;
}
