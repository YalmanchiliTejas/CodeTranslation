#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

int x, y, z, cnt;

int main(){
	while(~scanf("%d %d %d", &x, &y, &z)){
		cnt = 0;
		x -= z;
		while(x >= y + z){
			x = x - (y + z);
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}