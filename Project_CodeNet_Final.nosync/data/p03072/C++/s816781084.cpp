#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cassert>
#define maxn 
#define maxm 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
//#define DEBUG
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int max = 0, sum = 0, x;
	rep(i, 1, n) {
		scanf("%d", &x);
		if (x >= max) sum++, max = x;
	}
	printf("%d", sum);
}