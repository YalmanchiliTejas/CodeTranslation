#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack> 
#include<queue>
#include<set>
#include<map>
#define LL long long
#define N 105
#define MOD 1000000007
#define FOR(i,l,r) for (int i = (l); i <= (r); i ++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define INF 0x7fffffff
#define pb push_back
#define X first
#define Y second
#define eps 1e-6
using namespace std;
char mp[N][N];
int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	FOR(i,1,h) {
		scanf("%s",mp[i] + 1);
		mp[i][w + 1] = '.';
		mp[i][0] = '.';
	}
	FOR(i,1,w) mp[h + 1][i] = '.';
	int px = 1,py = 1,flag = 1;
	while (1){
		if (mp[px + 1][py] == '#' && mp[px][py + 1] == '#'){
			flag = 0;
			break;
		}
		else if (mp[px + 1][py] == '#'){
			if (mp[px + 1][py - 1] == '#'){
				flag = 0;
				break;
			}
			px ++;
		}
		else if (mp[px][py + 1] == '#'){
			if (mp[px - 1][py + 1] == '#'){
				flag = 0;
				break;
			}
			py ++;
		}
		else{
			flag = 0;
			break;
		}
		if (px == h && py == w) break;
	}
	if (flag) printf("Possible\n");
	else printf("Impossible\n");
}