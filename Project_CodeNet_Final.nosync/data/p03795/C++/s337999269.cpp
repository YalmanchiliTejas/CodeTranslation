#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int x = 0, y = 0;
	for(int i = 1; i <= n; i++) {
		x += 800;
		if(i % 15 == 0) y += 200;
	}
	printf("%d\n", x - y);
}
