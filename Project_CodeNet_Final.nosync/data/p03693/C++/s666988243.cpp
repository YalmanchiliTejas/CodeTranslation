#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;
 
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define INF 1<<25
 
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int d = a * 100 + b * 10 + c;
	if(d % 4)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}