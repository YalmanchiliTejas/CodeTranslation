#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
typedef vector<int> VI;
#define PB push_back
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main(){
	while(1){
		int n;
		cin >> n;
		if(n==0)return 0;
		VI v;
		int s=0;
		REP(i,n){
			int tmp;
			cin >> tmp;
			v.PB(tmp);
		}
		SORT(v);
		FOR(i, 1, n-1)s+=v[i];
		cout << s/(n-2) << endl;
	}
}