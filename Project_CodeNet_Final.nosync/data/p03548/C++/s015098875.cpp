#include<bits/stdc++.h>

using namespace std;

int main(){
	int x, y, z; scanf("%d %d %d", &x, &y, &z);
	int res; x -= z;
	/*if(x % (y + z) == 0) res = (x / (y + z)) - 1;
	else */res = x / (y + z);
	printf("%d\n", res);
}