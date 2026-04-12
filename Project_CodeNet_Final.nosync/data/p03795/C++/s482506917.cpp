#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int main(){
	int N;
	
	cin >> N;
	
	int waribiki = N/15;
	
	int ans = N*800-waribiki*200;
	
	cout << ans << endl;	

	return 0;
}
