#include <bits/stdc++.h>
using namespace std;

int a[300001];
bool solve1(int n){
	int p = 0;
	for(int i = 0;i < n;i++){
		if(i > p)return 0;
		p = max(p, i+(a[i]/10));
	}
	return p >= n-1;
}

bool solve2(int n){
	int p = n-1;
	for(int i = n-1;i >= 0;i--){
		if(i < p)return 0;
		p = min(p, i-(a[i]/10));
	}
	return p <= 0;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)scanf("%d", &a[i]);
	bool x = solve1(n);
	bool y = solve2(n);
	if(x && y)printf("yes\n");
	else printf("no\n");
	return 0;
}
