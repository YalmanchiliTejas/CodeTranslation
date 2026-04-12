#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;
LL li[3005];
LL memo[3005][3005];

LL dp(int l, int r){
   if(l>r) return 0LL;
   LL &ret = memo[l][r];
   if(ret!=-1) return ret;
   ret = max(-1LL*dp(l+1,r) + li[l] , -1LL*dp(l,r-1)+li[r]);
   return ret;
}

int main(){
   memset(memo,-1,sizeof(memo));
   scanf("%d",&n);
   for(int i=1;i<=n;i++) scanf("%lld",&li[i]);
   LL ans = dp(1,n);
   printf("%lld\n",ans);
	return 0;
}
