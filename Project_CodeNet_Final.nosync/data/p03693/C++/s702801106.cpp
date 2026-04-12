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

	int r, g, b;
	cin >> r >> g >> b;
	int a = 100*r + 10*g + b;
	if((a % 4) == 0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}

