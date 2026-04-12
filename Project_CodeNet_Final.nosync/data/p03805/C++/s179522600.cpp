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

int n, m;
std::vector<int> edge[10];
bool used[10];
int cnt;

void check(int a, int depth){
	if(depth == n){
		cnt++;
		return;
	}
	used[a] = true;
	for(int i = 0; i < edge[a].size(); i++){
		int b = edge[a][i];
		if(!used[b]){
			check(b, depth+1);
		}
	}
	used[a] = false;
	return;
}

signed main(){
	scanf("%ld %ld", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%ld %ld", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	check(1, 1);
	printf("%ld\n", cnt);
	return 0;
}
