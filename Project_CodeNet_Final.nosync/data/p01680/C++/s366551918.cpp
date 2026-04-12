#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

int N,M,com,x,y;
int height[100000],parent[100000];

int find(int x){
	if(x == parent[x])return x;
	else{
		return parent[x] = find(parent[x]);
	}
}

bool isSame(int x,int y){
	return find(x) == find(y);
}

void unite(int x,int y){
	x = find(x);
	y = find(y);

	if(x == y)return;

	if(height[x] < height[y]){
		parent[x] = y;
	}else{
		parent[y] = x;
		if(height[x] == height[y])height[x]++;
	}
}

int main(){

	while(true){
		scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)break;

		for(int i = 0; i < N; i++){
			height[i] = 0;
			parent[i] = i;
		}

		int a,b;

		for(int i = 0; i < M; i++){
			scanf("%d %d",&a,&b);
			a--,b--;
			unite(a,b);
		}

		int count = 0;
		for(int i = 0; i < N; i++){
			if(parent[i] == i)count++;
		}

		ll ans = 1;
		for(int i = 0; i < count; i++)ans = ans*2%MOD;

		if(count != N){
			ans = (ans+1)%MOD;
		}

		printf("%lld\n",ans%MOD);
	}

	return 0;
}