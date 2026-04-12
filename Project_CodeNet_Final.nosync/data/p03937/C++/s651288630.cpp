#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define LL long long
#define ULL unsigned long long
using namespace std;

int h,w,t;
char a[10];

int main() {
	cin>>h>>w;
	REP(i,h) {
		cin>>a;
		t += count(a, a+10, '#');
	}
	cout<<(t==(h+w-1)?"Possible":"Impossible")<<endl;
}
