#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define mst(a, b)	memset(a, b, sizeof a)
#define REP(i, x, n)	for(int i = x; i <= n; ++i)
const int qq = 2e5 + 10;

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int d = a * 100 + b * 10 + c;
	if(d % 4 == 0){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}