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
const ll INF = 1e18;
const int MOD = 1e9 + 7;

char a;
int main(void) {
	cin >> a;
	if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')ct("vowel");
	else ct("consonant");
	
	return 0;
}