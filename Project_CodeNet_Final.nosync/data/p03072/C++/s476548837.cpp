#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <array>

using namespace std;

int main() {
	
	int N;
	vector<int> H;
	int l;
	int m = 0;
	int ans = 0;
	
	// 入力
	scanf("%d", &N);
	for(int i = 0; i<N; i++){
		scanf("%d", &l);
		H.push_back(l);
	}
	
	for(int i=0; i<N; i++){
		if(m <= H[i]){
			ans++;
			m = H[i];
		}
	}
	
	// 出力
	printf("%d\n", ans);
	
	return 0;
	
}
