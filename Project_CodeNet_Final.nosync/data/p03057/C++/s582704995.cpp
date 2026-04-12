#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

int f[200005];

int solve(int n,int up) {
  int s=0;
  for(int i=1;i<=n;i++) {
  	if (i>up+1) s=(s-f[i-up-1]+MOD)%MOD;
  	f[i]=(s+((i<=up)?i:0))%MOD;
  	s=(s+f[i])%MOD;
  }
  return f[n];
}

int solve2(int n) {
  f[1]=1;
  for(int i=2;i<=n+1;i++) f[i]=(f[i-1]+f[i-2])%MOD;
  return (f[n+1]+f[n-1])%MOD;
}

char str[200005];

int main() {
  int n,m;
  scanf("%d%d%s",&n,&m,str+1);
  if (str[1]=='B') {
  	for(int i=1;i<=m;i++) str[i]=((str[i]=='R')?'B':'R');
  }
  bool v=0;
  for(int i=1;i<=m;i++)
    if (str[i]=='B') {
    	v=1;
    	break;
	}
  if (!v) {
  	printf("%d\n",solve2(n));
  	return 0;
  }
  if (n&1) {
  	puts("0");
  	return 0;
  }
  int minn=n,s=0;
  bool fir=1;
  for(int i=1;i<=m;i++)
    if (str[i]=='R') s++;
    else {
    	if (s&&(fir||(s&1))) minn=min(minn,s);
    	s=fir=0;
	}
  printf("%d\n",2*solve(n>>1,(minn>>1)+1)%MOD);
  return 0;
}