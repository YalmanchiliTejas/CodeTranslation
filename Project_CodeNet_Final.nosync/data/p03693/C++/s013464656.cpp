#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
	scanf("%d %d %d", &a, &b, &c);
	a = a * 100 + b * 10 + c;
	if(a % 4 == 0){
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
