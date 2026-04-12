#include <cstdio>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pb push_back
#define fi first
#define se second
#define SIZE 100333
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

int main () {
	char str[100111];
	int n, chk[100111];
	scanf("%d",&n);
	scanf("%s",str);
	for(int cnt=3;cnt>=0;cnt--) {
		memset(chk,0,sizeof(chk));
		// printf("cnt %d\n",cnt);
		// 1 : sheep, 0 : wolf
		chk[0] = (cnt & 1) ? 1 : 0;
		chk[1] = (cnt & 2) ? 1 : 0;
		for(int i=1;i<n-1;i++) {
			if((str[i] == 'o' && chk[i]) || (str[i] == 'x' && !chk[i]))	chk[i+1] = chk[i-1];
			else													chk[i+1] = 1 - chk[i-1];
		}
		// last chk
		if (((!chk[n-1] && str[n-1] == 'x') || (chk[n-1] && str[n-1] == 'o')) && chk[n-2] != chk[0])		continue;
		if (((!chk[n-1] && str[n-1] == 'o') || (chk[n-1] && str[n-1] == 'x')) && chk[n-2] == chk[0])		continue;
		if (((!chk[0] && str[0] == 'o') || (chk[0] && str[0] == 'x')) && chk[n-1] == chk[1])				continue;
		if (((!chk[0] && str[0] == 'x') || (chk[0] && str[0] == 'o')) && chk[n-1] != chk[1])				continue;
		for(int i=0;i<n;i++)	printf("%c",chk[i] ? 'S' : 'W');
		printf("\n");
		return 0;
	}
	printf("-1\n");
}