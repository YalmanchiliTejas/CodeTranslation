#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//typedef pair<int,int> P;


int main(){
	int x,y,z;
	scanf("%d %d %d", &x, &y, &z);

	int ans = 0;
	while(ans*(y+z)+z <= x){
		ans++;
	}
	printf("%d\n", ans-1);

	return 0;
}
