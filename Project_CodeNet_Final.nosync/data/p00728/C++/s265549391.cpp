//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
using namespace std;
#define INF 100000005
#define MAX 200005

int a[1001];
int main(){
	int n, sum;
	while(cin >> n, n){
		sum = 0;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			sum += a[i];
		}
		sum -= *max_element(a, a+n);
		sum -= *min_element(a, a+n);
		cout << sum/(n-2) << endl;
	}
	return 0;
}