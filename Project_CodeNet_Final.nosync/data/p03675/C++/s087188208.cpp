#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//infinity
#define INTINF 2000000000
#define LONGINF 2000000000

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(){
	int n; cin >> n;
	int a[n];
	REP(i, n) cin >> a[i];

	for(int i = n-1; i >= 0; i-=2){
		if(i==n-1){
			cout << a[i];
		}else{
			cout << " " << a[i];
		}
	}

	for(int i = n%2; i < n; i+=2){
		cout << " " << a[i];
	}

	cout << endl;
	return 0;
}
