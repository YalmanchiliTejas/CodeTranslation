#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int N = 2e5+7,INF = 0x7f7f7f7f;
ll a[N],f[N],s[N];
int main()
{
    int n;scanf("%d",&n);
    for(int i = 1;i <= n;++i)	scanf("%lld",&a[i]);
	s[1] = a[1];
	for(int i = 2;i <= n;++i)
		s[i] = s[i - 2] + a[i];
	f[2] = max(a[1],a[2]);
	for(int i = 3;i <= n;++i)
		if(i & 1)	f[i] = max(f[i - 1],f[i - 2] + a[i]);
		else	f[i] = max(f[i - 2] + a[i],s[i - 1]);
    printf("%lld",f[n]);
    return 0;
}
