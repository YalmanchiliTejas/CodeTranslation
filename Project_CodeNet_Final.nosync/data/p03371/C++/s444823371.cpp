#include<iostream>
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
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	long long price = LONGINF;
	FOR(i, 0, 100000 + 1){
		long long p;
		p = i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B;
		price = min(price, p);
	}
	cout << price << endl;

	return 0;
}
