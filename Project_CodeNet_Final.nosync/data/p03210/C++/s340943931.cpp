#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
 
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define INF 1<<25
 
int main()
{
	int n;
	cin >> n;
	if (n == 7 || n == 5 || n == 3) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}