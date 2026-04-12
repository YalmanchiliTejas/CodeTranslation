#include <bits/stdc++.h>
using namespace std;

int x, y, z, cnt;

int main(){
	scanf("%d%d%d",&x,&y,&z);
	x -= z;
	while(x>=y+z){
		cnt ++;
		x -= y+z;
	}
	printf("%d\n",cnt);
	return 0;
}