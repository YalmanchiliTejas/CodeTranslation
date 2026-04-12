#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
const int MaxN = 50;
LL a[MaxN + 5];
LL cnt[MaxN + 5];
int n;
 
int main(){
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		LL tot = 0, ans = 0;
		bool flag = true;
		while(flag){
			flag = false;
			tot = 0;
			for(int i = 1; i <= n; i++){
				cnt[i] = a[i] / n;
				a[i] = a[i] % n;
				tot += cnt[i];
			}
			ans += tot;
			for(int i= 1; i <= n; i++){
				a[i] += tot - cnt[i];
				if(a[i] >= n) flag = true;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
