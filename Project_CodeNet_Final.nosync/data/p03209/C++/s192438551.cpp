#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, i;
	long long k, pt[55] = {1}, bg[55] = {1}, ans = 0;
	scanf("%d%lld", &n, &k);
	for(i = 1; i <= n; i++){
		bg[i] = 2*bg[i-1] + 3;
		pt[i] = 2*pt[i-1] + 1;
	}
	for(int i = n-1; i >= 0; i--){
		if(k == bg[i+1]){
			ans += pt[i+1];
			break;
		}else if(k > bg[i] + 2){
			ans += pt[i] + 1;
			k -= bg[i] + 2;
			if(!i) ans++;
		}else if(k == bg[i] + 2){
			ans += pt[i] + 1;
			break;
		}else if(k > 1){
			k--;
			if(!i) ans++;
		}else break;
	}
	printf("%lld\n", ans);
}