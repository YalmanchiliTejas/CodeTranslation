#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack> 
#include<queue>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define ULL unsigned long long
#define N 1000100
#define M 5010
#define MOD 1000000007
#define FOR(i,l,r) for (int i = (l); i <= (r); i ++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define INF 0x3f3f3f3f
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define X first
#define Y second
using namespace std;
char st[10];
int main(){
	scanf("%s",st);
	int len = strlen(st);
	int flag = 0;
	for (int i = 0; i < len - 1; i ++) if (st[i] == 'A' && st[i + 1] == 'C'){
		flag = 1;
		break;
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
}