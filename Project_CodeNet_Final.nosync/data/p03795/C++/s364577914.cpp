#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<list>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
#define REP(i,m,n) for(int i = (m); i < (n);i++)
#define rep(i,n) REP(i,0,n)


int main() {
	int n;
	cin >> n;
	cout << 800 * n - (n/15)*200 << endl;
	return 0;
}
