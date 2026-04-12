#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iomanip>
#include<string>
#include <numeric>
using namespace std;
int a[810];
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
	int n;
	cin >> n;
	int iwa = 0;
	int ans = 1000;
	rep(i, n) {
		cin >> a[i];
		iwa += a[i];
		if ((iwa / (i+1))<= ans) { ans = iwa / (i+1); }
	}
	cout << ans << endl;
}




