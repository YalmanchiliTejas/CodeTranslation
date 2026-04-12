#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define maxn 500009
using namespace std;
int n;
int b[maxn];
int a[maxn];
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int p = 1, q = n;
	int sg = 1;
	for(int i  = n; i >= 1; i--){
		if(sg == 1){
			b[p++] = a[i];
		}
		else{
			b[q--] =a[i];
		}
		sg *= -1;
	}
	for(int i = 1; i <= n; i++){
		printf("%d", b[i]);
		if(i == n)
			puts("");
		else
			printf(" ");
	}
	return 0;
}