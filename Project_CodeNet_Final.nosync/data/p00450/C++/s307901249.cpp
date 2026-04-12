#include <bits/stdc++.h>
using namespace std;

int go[100000];

int main()
{
	int n;
	while (scanf("%d", &n), n){
		for (int i = 0; i < n; i++){
			scanf("%d", &go[i]);
			
			int p = i - 1;
			if (i % 2 == 1){
				while (p >= 0 && go[i] != go[p]){
					go[p] = go[i];
					p--;
				}
			}
		}
		
		int cnt = 0;
		for (int i = 0; i < n; i++){
			cnt += !go[i];
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}