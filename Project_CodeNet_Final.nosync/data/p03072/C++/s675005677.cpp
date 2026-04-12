#include <bits/stdc++.h>
using namespace std;

int n, arr[25], maxi, ans;

int main(){
	scanf("%d", &n);
	ans = 1;
	scanf("%d", &arr[0]);
	maxi = arr[0];

	for(int i = 1; i < n; i++){
		scanf("%d", &arr[i]);
		maxi = max(maxi, arr[i-1]);
		if(arr[i] >= maxi){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}