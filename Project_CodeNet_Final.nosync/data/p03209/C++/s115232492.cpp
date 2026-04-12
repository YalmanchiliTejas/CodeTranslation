#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;


i64 n, m;
i64 h[55], p[55];

void init(){
	i64 cnt = 1;
	h[0] = 1;
	for(int i = 1; i <= n; i++){
		cnt = cnt*2 + 3;
		h[i] = cnt;
	}
	cnt = 1;
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		cnt = cnt*2 + 1;
		p[i] = cnt;
	}
}

i64 solve(int a, i64 b){
	if(a == 0) return 1;
	if(b == 1) return 0;
	if(b < 2 + h[a-1]) return solve(a-1, b-1);
	if(b == 2 + h[a-1]) return p[a-1] + 1;
	if(b < h[a]) return p[a-1]+1 + solve(a-1, b-2-h[a-1]);
	if(b == h[a]) return p[a];
}

int main(){
	cin >> n >> m;
	init();
	
	cout << solve(n, m) << endl;
	
	return 0;
}