#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i=(a);i<(n);++i)
#define per(i, a, n) for(int i=(a);i>(n);--i)
#define pb emplace_back
#define mp make_pair
#define lowbit(x) (x & -x)

typedef long long LL;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1.0);

int n;

int main(){
	scanf("%d", &n);
	puts(n>=30?"Yes":"No");
	return 0;
}
