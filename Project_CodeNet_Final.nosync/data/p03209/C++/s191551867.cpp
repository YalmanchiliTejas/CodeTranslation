#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int n;
ll x;
ll num[55],len[55];

ll dfs(int lev,ll pos){
	if(lev == 1){
		if(pos >= 1)
		    if(pos <= 4)
		        return pos - 1;
		    else
		        return 3;
		else
		    return 0ll;
	}
	if(pos <= 1)
	    return 0ll;
	if(pos == 2 + len[lev - 1])
	    return num[lev - 1] + 1;
	if(pos < 2 + len[lev - 1])
	    return dfs(lev - 1,pos - 1);
	if(pos == len[lev - 1] * 2 + 3)
	    return num[lev - 1] * 2 + 1;
	return 1 + num[lev - 1] + dfs(lev - 1,pos - len[lev - 1] - 2);
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	num[0] = 1;
	len[0] = 1;
	for(int i = 1;i <= 50;i++){
	    num[i] = num[i - 1] * 2 + 1;
	    len[i] = len[i - 1] * 2 + 3;
	}
	scanf("%d%lld",&n,&x);
	printf("%lld",dfs(n,x));
	return 0;
}
