
#include<cstdio>
#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
using namespace std;
using ll = long long;



int main(){
	int n, s[100];
	while (1){
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> s[i];
		sort(s, s + n);
		int k = 0;
		for (int i = 1; i < n - 1; i++) {
			k += s[i];
		}
		cout << k / (n-2) << endl;
	}

}

