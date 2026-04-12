#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

LL P = 1000000007LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	vector<LL> A;
	LL S = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		LL a;
		cin >> a;
		A.push_back(a);
		S += a;
	}

	LL ans = 0;
	for(int i=0; i<N-1; i++){
		S = S - A[i];
		S %= P;
		if(S < 0){
			S += P;
		}
		ans += (A[i] * S);
		ans %= P;
		if(ans < 0){
			ans += P;
		}
	}
	ans %= P;
	if(ans < 0){
		ans += P;
	}
	printf("%lld\n", ans);
	return 0;
}