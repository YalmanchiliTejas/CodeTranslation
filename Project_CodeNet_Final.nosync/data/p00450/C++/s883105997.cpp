#include <bits/stdc++.h>
using namespace std;

int n,d[100003],ans;

int gya(int x){
	if(x == 1) return 0;
	else return 1;
}

int main(){
	while(1){
	scanf("%d",&n);
	int h[2][100004] = {0};
	ans = 0;
	if(n == 0)break;
	for(int i = 1;i <= n;i++){
		scanf("%d",&d[i]);
	}
	int pre = -1;
	for(int i = 1;i <= n;i++){
		if(i % 2 == 1){
			h[d[i]][i] = h[d[i]][i-1] + 1;
			h[gya(d[i])][i] = 0;
			if(d[i] == 0)ans++;
			pre = d[i];
		}else{
			if(pre == d[i]){
				if(d[i] == 0)ans++;
				h[d[i]][i] = h[d[i]][i-1] + 1;
				h[gya(d[i])][i] = 0;
				continue;
				pre = d[i];
			}
			int gyaku = gya(d[i]);
			int change = h[gyaku][i-1];
			if(d[i] == 0)ans += change + 1;
			else ans -= change;
			h[d[i]][i] = h[d[i]][i-change-1] + change + 1;
			pre = d[i];
		}
	}
	printf("%d\n",ans);
	}
	return 0;
}
