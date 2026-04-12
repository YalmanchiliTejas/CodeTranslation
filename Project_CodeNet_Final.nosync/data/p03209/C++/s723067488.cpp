#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18

priority_queue<llint,vector<llint>,greater<llint>> que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
llint n,x;
llint a[55],b[55];

llint calc(llint N,llint X){
	if(X<=0)return 0;
	if(N<=0)return 1;
	if(X>a[N]/2){
		return b[N-1]+1+calc(N-1,X-1-a[N]/2);
	}
	else{
		return calc(N-1,X-1);
	}
}

void solve(){
	cin >> n >> x;

	a[0]=1;
	b[0]=1;
	for(int i=1;i<51;i++){
		a[i]=2*a[i-1]+3;
		b[i]=2*b[i-1]+1;
	}
	cout << calc(n,x) << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
