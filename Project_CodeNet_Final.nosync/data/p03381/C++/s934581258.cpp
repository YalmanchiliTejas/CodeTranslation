/*
 * ARC097_C.cpp
 *
 *  Created on: May 18, 2018
 *      Author: 13743
 */
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

int x[200001];
int order[200001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	REP(i, N) {
		cin >> x[i];
		order[i] = x[i];
	}
	sort(order, order+N);

	int mid = N / 2;
	REP(i, N) {
		int xx = x[i];
		int piv = lower_bound(order, order+N, xx) - order;
		if(piv >= mid) {
			cout << order[mid-1] << "\n";
		}
		else {
			cout << order[mid] << "\n";
		}
	}

	cout << flush;
}




