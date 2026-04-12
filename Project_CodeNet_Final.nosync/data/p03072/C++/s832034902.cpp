#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, i, ans = 0;
	scanf("%d", &N);
	vector<int> H(N);
	for(i = 0; i < N; i++){
		scanf("%d", &H[i]);
		int f = 1, j;
		for(j = 0; j < i; j++){
			if(H[j] > H[i]){
				f = 0;
			}
		}
		ans += f;
	}
	printf("%d\n", ans);
	return 0;
}