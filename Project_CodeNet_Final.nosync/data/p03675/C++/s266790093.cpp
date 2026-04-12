#include <iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define OREP(i,n) FOR(i,1,n)
#define GREY 2
#define WHITE 1
#define BLACK 0
//#define x first
//#define y second
ll n,f=0,s=0; vector<ll> b, a,fir,sec;
ll gomi,co=0;
int main() {
	cin >> n; ll div = (n+1) % 2;
	REP(i, n) {
		cin >> gomi; 
		if ((i+1 )% 2==div) {
			sec.push_back(gomi); s++;
		}
		else { fir.push_back(gomi); f++; }
	}
	REP(i, (f +1) / 2) { swap(fir[i], fir[f - i-1]); }
	REP(i, f) { if (i) { cout << " "; }cout << fir[i]; }
	REP(i, s) { cout << " " << sec[i]; }cout << endl;
	return 0;
}