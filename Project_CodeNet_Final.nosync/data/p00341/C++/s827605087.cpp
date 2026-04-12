#include <bits/stdc++.h>
using namespace std;

int a[12], f = 0;
int main(){
	for(int i = 0;i < 12;i++)scanf("%d", &a[i]);
	sort(a, a+12);
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++)if(a[i*4+j] == a[i*4+j+1])f++;
	}
	if(f == 9)printf("yes\n");
	else printf("no\n");
	return 0;
}
