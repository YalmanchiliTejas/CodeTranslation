/*
 * ARC091_D.cpp
 *
 *  Created on: May 22, 2018
 *      Author: 13743
 */
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
typedef long long lng;
typedef unsigned long long ulng;

#define pb push_back
#define SZ(a) int((a).size())
#define ALL(a) (a).begin(), (a).end
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,b,a) for(int i=(b); i>=(a); --i)
#define REP(i,n) FOR(i,0,n-1)
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

lng power(lng b, lng e) {lng sol=1; while(e>0) {if(e&1) {sol=sol*b;} e>>=1; b*= b;} return sol;}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	lng N, K;
	cin >> N >> K;

	if(K == 0) {
		cout << N*N << endl;
		return 0;
	}
	lng ans = 0;
	FOR(b, K+1, N) {
		ans += (b-K)*(N/b);
		ans += max(0LL, N%b-K+1);
	}

	cout << ans << endl;
}




