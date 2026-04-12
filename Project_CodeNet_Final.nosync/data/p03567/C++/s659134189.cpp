#include <bits/stdc++.h>
using namespace std;
char lx = ' ', cx = ' ';
int main(){
	while(scanf("%c", &cx) != EOF){
		if(cx == 'C' && lx == 'A') {
			printf("Yes\n");
			return 0;
		}
		lx = cx;
	}
	printf("No\n");
}