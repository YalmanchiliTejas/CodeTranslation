#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define RREP(i,n) RFOR(i,0,n)

const int _N = 3e5 + 100;

int n;

int d[_N];
int main(){
	cin >> n;
	REP(i, n){
		cin >> d[i];
		d[i] /= 10;
	}

	int i=0, cango=0;
	for(;i <= min(cango, n-1);i++){
		cango = max(cango, i+d[i]);
	}
	if(cango<n){
		cout << "no" << endl;
		return 0;
	}

	i=0;cango=0;
	for(;i <= min(cango, n-1);i++){
		cango = max(cango, i+d[n-1-i]);
	}
	if(cango<n){
		cout << "no" << endl;
		return 0;
	}

	cout << "yes" << endl;
}