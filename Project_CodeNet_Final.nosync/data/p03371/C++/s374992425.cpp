#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
using namespace std;
 
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define INF 1<<25
 
int main()
{
	int a, b, c, x, y;
	int cost = 0;
	cin >> a >> b >> c >> x >> y;
	while(x > 0 || y > 0) {
		if (x > 0 && y > 0) {
			if (a + b > c * 2) {
				cost += c * 2;
			} else {
				cost += a + b;
			}
			x--;
			y--;
		} else if(x > 0) {
			if (a > c * 2) {
				cost += c * 2;
			} else {
				cost += a;
			}
			x--;
		} else if(y > 0) {
			if (b > c * 2) {
				cost += c * 2;
			} else {
				cost += b;
			}
			y--;
		}
	}
	cout << cost << endl;
	return 0;
}