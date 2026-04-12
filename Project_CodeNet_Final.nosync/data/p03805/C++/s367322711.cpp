#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>

//#include<bits/stdc++.h>


using namespace std;



int main() {

	int n, m;
	cin >> n >> m;
	vector<int>p(n);
	for (int i = 0; i < n; i++)p[i] = i + 1;
	bool f[10][10] = {};
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		f[a][b] = 1;
		f[b][a] = 1;
	}
	int ans = 0;
	do {
		
		if (p[0] == 1) {bool r = 0;
			for (int i = 0; i < n-1; i++) {
				if (!f[p[i]][p[i + 1]])r = 1;
			}
			if (!r)ans++;
		}

	} while (next_permutation(p.begin(),p.end()));

	cout << ans << endl;
	return 0;


}