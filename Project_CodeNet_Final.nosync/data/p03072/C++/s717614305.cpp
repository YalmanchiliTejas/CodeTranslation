	#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <deque>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <ctime>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <stdlib.h>
#define ms(a) memset(a,0,sizeof(a))
#define st(a,n) sort(a,a+n)
#define fr(i,k,n) for(int i=k;i<=n;++i)
#define FR(i,k,n) for(int i=n;i>=k;--i)
#define pb push_back
#define inf 0x3f3f3f
#define vc vector
#define exp 1e-6
#define ci cin
#define co cout
#define ed endl
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int mod =1e9+7;
const int maxn=1e5+10;
const double pi=acos(-1);
int main()
{
    int n;
    ci>>n;
    int ans=1,pos=0;
    while(n--)
    {
        int x;
        ci>>x;
        if(ans<=x)
            ans=x,pos++;
    }
    co<<pos<<ed;
    return 0;
}

