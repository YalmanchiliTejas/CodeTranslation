#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define fn fill_n
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> P;

llong n, x;
llong many[51] = {}, paty[51] = {};

llong solve(llong eat, int level){
	if(eat == 0) return 0;
	if(level < 0) return 0;
	if(eat == many[level]) return paty[level];

	llong ret = 0;

	if(eat <= many[level]/2){
		eat--;
	}else{
		eat -= many[level]/2+1;
		ret = paty[level-1]+1;
	}

	return ret + solve(eat, level-1);
}

int main(){
	many[0] = 1, paty[0] = 1;
	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		many[i] = many[i-1]*2+3;
		paty[i] = paty[i-1]*2+1;
	}

	cout << solve(x, n) << endl;

	return 0;
}