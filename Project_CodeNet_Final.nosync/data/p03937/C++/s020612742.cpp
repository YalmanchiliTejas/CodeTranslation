#include<stdio.h>
#include<queue>
#include<assert.h>
#include<tuple>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MX = 20;
const int MM = 1000000007;

char D[MX][MX];

int main()
{
	int N, M, cnt = 0;;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%s", D[i]);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cnt += D[i][j] == '#';
		}
	}
	if( cnt != N+M-1 ) return !printf("Impossible\n");
	int x = 0, y = 0;
	for(int i = 1; i < cnt; i++){
		if( D[x+1][y] == '#' ) x++;
		else if( D[x][y+1] == '#' ) y++;
		else return !printf("Impossible\n");
	}
	printf("Possible\n");
}
