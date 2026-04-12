#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;

const int p = 1e9 + 7;
int x, sum, ans;
int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		ans = (ans + 1ll * x * sum) % p;
		sum = (sum + x) % p;
	}
	printf("%d", ans);
}