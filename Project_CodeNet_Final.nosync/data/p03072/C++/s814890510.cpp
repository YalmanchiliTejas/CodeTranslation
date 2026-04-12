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
#define VREP_ll(v) for(std::vector<ll>::iterator itr = (v).begin(); itr != (v).end();itr++)
#define VREP_int(v) for(std::vector<int>::iterator itr = (v).begin(); itr != (v).end();itr++)
#define VALL(v) ((v).begin(),(v).end())
#define errln(v) cerr << (v) << endl;
#define println(v) cout << (v) << endl;

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	int hmax=0,h,ret=0;
	REP(i,n){
		cin >> h;
		if(hmax <= h){
			ret++;
		}
		hmax = max(hmax,h);
	}
	println(ret);
	return 0;
}
