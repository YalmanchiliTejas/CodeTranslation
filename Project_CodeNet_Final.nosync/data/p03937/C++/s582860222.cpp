#include <bits/stdc++.h>

#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)

#define LL long long
#define Ldouble long double
#define PI 3.14159265358979323846264338327950288419

#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int h, w, cnt;
char s[10][10];

int main(){
	scanf("%d %d", &h, &w);
	FI(i, 1, h) scanf(" %s", s[i] + 1);
	FI(i, 1, h) FI(j, 1, w) if(s[i][j] == '#') cnt++;
	if(cnt != h + w - 1 || s[1][1] != '#' || s[h][w] != '#'){
		printf("Impossible\n");
		return 0;
	}
	int cx = 1, cy = 1;
	while(cx < h || cy < w){
		if(s[cx + 1][cy] == '#') cx++;
		else if(s[cx][cy + 1] == '#') cy++;
		else{
			printf("Impossible\n");
			return 0;
		}
	}
	printf("Possible\n");
	return 0;
}
