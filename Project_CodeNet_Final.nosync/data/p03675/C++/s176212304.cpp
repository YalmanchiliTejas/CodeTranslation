#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 200009;
int n, m, a, t, ans[maxn];

int main(){
	scanf("%d", &n);
	m = n/2+1; t = 0;
	for (int i=1; i<=n; i++){
		scanf("%d", &a);
		if (n&1){
			if (i&1) ans[m-t] = a;
			else ans[m+t] = a;
		}
		else{
			if (i&1) ans[m+t] = a;
			else ans[m-t] = a;
		}
		if (i&1) t++;
	}
	for (int i=1; i<=n; i++)
		printf("%d ", ans[i]);
	return 0;
}