#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define scd(n) scanf("%d",&n)
#define scl(n) scanf("%I64d",&n)
#define mp(x,y) make_pair(x,y)
#define repi(a,b,c) for(int i=a;i<b;i+=c)
#define repis(a,b,c) for(int i=a-1;i>=b;i-=c)
#define repj(a,b,c) for(int j=a;j<b;j+=c)
#define repjs(a,b,c) for(int j=a-1;j>=b;j-=c)
#define fi first
#define se second

const int mx = 2e5+100;

int main() {
    int a,b,c,ans;
    scd(a);
    scd(b);
    scd(c);
    ans = a*100+b*10+c;
    if(ans%4 == 0) printf("YES\n");
    else printf("NO\n");
}
