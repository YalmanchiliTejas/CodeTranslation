#include<bits/stdc++.h>
using namespace std;
int r, g, b;

int main(){
	scanf("%d %d %d", &r, &g, &b);
	int sum = r*100+g*10+b;
	if(sum%4==0)
		printf("YES");
	else 
		printf("NO");
	return 0;
	
	
}