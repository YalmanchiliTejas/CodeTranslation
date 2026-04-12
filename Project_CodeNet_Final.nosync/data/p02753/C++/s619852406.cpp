#include<cstdio>
#include <algorithm>
#include <iostream>
#include <functional>
#include<cmath>
#include<string.h>
#include<vector>

int main(){
	char a[4];
	scanf("%s",a);
	if(a[0]==a[1]&&a[0]==a[2]) printf("No\n");
	else printf("Yes\n");
	return 0;
}