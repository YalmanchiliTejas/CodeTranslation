#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int maxN = 2 * 1e5 + 5;
int N, a[maxN], b[maxN]; 
map<int, int> mp;
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) scanf("%d", &a[i]), b[i] = a[i];
	sort(a + 1, a + 1 + N);
	for(int i = 1; i <= N; ++i) mp[a[i]] = N - i + 1;
	for(int i = 1; i <= N; ++i) {
		if(mp[b[i]] <= N / 2) printf("%d\n", a[N / 2]);
		else printf("%d\n", a[N / 2 + 1]);
	} 
	return 0;
}