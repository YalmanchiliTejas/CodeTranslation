#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#pragma warning(disable: 4996)
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
	
	int N, M;

	cin >> N >> M;
	bool ans = false;
	if (N == M) {
		ans = true;
	}
	puts(ans ? "Yes" : "No");
	return 0;
}