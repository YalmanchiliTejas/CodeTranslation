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


int main(int argc, char* argv[]){
	long long A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	//ABピザを2k枚買うとする
	//Aピザ k枚、Bピザk枚できる。
	//のこりAピザ (X-k)枚、Bピザ(Y-k)枚買う必要がある。
	long long k;
	long long ans = (1LL<<62);

	for(k = 0; k <= max(X, Y); k++){
		long long v = C * 2 * k;
		v += A * max(X - k, 0LL);
		v += B * max(Y - k, 0LL);
		if(ans > v){
			ans = v;
		}

	}
	printf("%lld\n", ans);
	return 0;
}