#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>

#define int long

const int INF = 1000000009;
const long LINF = 1123456789012345678;

int h, w;
char field[10][10];


signed main(){
	scanf("%ld %ld", &h, &w);
	for(int i = 0; i < h; i++){
		scanf("%s", field[i]);
	}
	for(int i = 0; i < h + w - 1; i++){
		int cnt = 0;
		for(int j = std::max(0l, i-w+1); j <= i; j++){
			if(field[j][i-j] == '#'){
				cnt++;
			}
		}
		//printf("%ld %ld\n", i, cnt);
		if(cnt != 1){
			printf("Impossible\n");
			return 0;
		}
	}
	printf("Possible\n");
	return 0;
}
