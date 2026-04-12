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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> H, T;
	int ans = 0;
	for(int i=0; i<N; i++){
		int h;
		cin >> h;
		H.push_back(h);
		if(i == 0){
			T.push_back(H[0]);
		}
		else{
			if(H[i] > T[i-1]){
				T[i] = H[i];
			}
			else{
				T[i] = T[i-1];
			}
		}
		if(H[i] >= T[i]){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

