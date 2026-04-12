#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
#define mp  std::make_pair
#define ll long long int
#define abs(n) ((n>0)?(n):((n)*(-1)))
#define CEIL(a,b) (((a) + ((b)-1)) / (b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define VREP(v) for(std::vector<ll>::iterator itr = (v).begin(); itr != (v).end();itr++)
#define VALL(v) ((v).begin(),(v).end())
#define errln(v) cerr << (v) << endl;
#define println(v) cout << (v) << endl;

int main(int argc, const char * argv[]) {
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;

	if(A + B < 2 * C){
		println(A*X+B*Y);
		return 0;
	}

	int more_cnt,more_price,common_cnt;

	common_cnt = min(X,Y);
	more_cnt = max(X,Y)-common_cnt;
	more_price = (X > Y) ? A : B;

	if(more_price > C * 2){
		println(C * 2 * max(X,Y));
	}else{
		println(C * 2 * common_cnt + more_cnt * more_price)
	}

	return 0;

}
