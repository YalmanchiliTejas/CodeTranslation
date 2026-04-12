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
#include<tuple>
#include<set>
#include<map>
#include<cctype>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
#define tget(a,b) get<a>(b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX_V = 100005;
int N;
int main(void) {
	
	cin >> N;
	if (N == 3 || N == 5 || N == 7)ct("YES");
	else ct("NO");
	return 0;
}