#include<stdio.h>
#include<cstdio>
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
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
const ll mod = 1e9 + 7;



ll N,ans;
ll H[200];


int main() {


	cin >> N;
	int cur = 0;
	FOR(i, 0, N) {
		cin >> H[i];
		if (H[i] >= cur) { ans++; cur = H[i]; }
	}

	ct(ans);

	return 0;
}