#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<iostream>
#include<queue>
#include<utility>
#include<string>
#define mp make_pair
#define inf 1000000000
using namespace std;
typedef long long ll;
int n,k;
ll ans;
int main(){
	//f_r_e_o_p_e_n 在洛谷中禁用！
	scanf("%d%d",&n,&k);
	if(k==0) ans = (ll)n * n;
	else
	for(int i=1;i<=n;i++){
		if(i<=k) continue;
		//余数可取：k,k+1,k+2,...,i-1.
		if(n%i<k) ans += n/i*(i-k);
		else ans += n/i*(i-k) + n%i-k+1;
	}
	printf("%lld\n",ans);
  return 0;
}