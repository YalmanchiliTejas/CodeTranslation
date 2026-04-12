#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main(){

	int n, h, max = 0, cont = 0;
	scanf("%d", &n);
	while (n--){
		scanf("%d ", &h);
		if (h >= max){
			max = h;
			cont ++;
		}
	}
	printf("%d\n", cont);
	return 0;
}