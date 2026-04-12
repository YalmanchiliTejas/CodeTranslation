#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<time.h>
#include<set>
#include<map>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
#define tget(a,b) get<a>(b)
using namespace std;
typedef long long ll;
const ll INF = 1e17;
const int MOD = 1e9 + 7;

int r,g, b;

int main(void) {
	cin >>r>> g >> b;
	if ((2 * g + b) % 4 == 0)ct("YES");
	else ct("NO");
	return 0;
}