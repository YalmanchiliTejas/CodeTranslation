/*===============================================================
*  Filename: E.cpp
*  Author: zhuyutian
*  Date: 2018.04.16
================================================================*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int maxn = 100005;

int n,K;

int main()
{
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
    scanf("%d%d",&n,&K);
	ll ans = 0;
	if(K == 0) ans = 1ll * n * n;
	for(int i = K; i <= n && K; i++){
		ans += n - i;
		for(int j = i; j <= n; j += i){
			if(j + i <= n) ans += i - K;
			else if(j + K <= n) ans += n - j - K + 1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
