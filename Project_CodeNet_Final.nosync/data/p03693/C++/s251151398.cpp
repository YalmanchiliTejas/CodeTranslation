#include <bits/stdc++.h>

using namespace std;

int r,g,b;

int main(){
	scanf("%d%d%d", &r, &g, &b);
	
	if((r * 100 + g * 10 + b) % 4 == 0)
	printf("YES\n");
	else
	printf("NO\n");
}