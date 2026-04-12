#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
using namespace std;
#define REP(i,n); for(int i = 0;i < (int)(n);i++)

int main() {
	int n,a,count=0;
	vector<int> h;
	cin >> n;
	h.resize(n);
	REP(i,n){
		cin >> h[i];
		a = 0
		REP(j,i + 1){
			a = max(a,h[j]);
		}
		if(a==h[i])count++;
	}
	cout << count;
	return(0);
}