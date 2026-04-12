#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = (a), i##_end_ = (b); i <= i##_end_ ; ++i)
#define drep(i, a, b) for(register int i = (a), i##_end_ = (b); i >= i##_end_ ; --i)
#define clear(a, b) memset((a), (b), sizeof(a))
typedef long long LL;
int read() {
	int x = 0, flag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch - 0x30);
		ch = getchar();
	}
	return flag * x;
}

#define Max 109
const int dir[2][2] = {{0, 1}, {1, 0}};
int H, W;
int ap[Max][Max], vis[Max][Max];
int l_ans;
int flag, Ktmp;
void dfs(int a, int b) {
	vis[a][b] = 1, ++Ktmp;
//	printf("(%d %d)\n", a, b);
	if(Ktmp == l_ans) {
		flag = 1;
		return ;
	}
	rep(i, 0, 1) {
		int nex = a + dir[i][0],
			ney = b + dir[i][1];
		if(1 <= nex && nex <= H && 1 <= ney && ney <= W)
			if(!vis[nex][ney] && ap[nex][ney]) dfs(nex, ney);
		if(flag) break;
	}
	vis[a][b] = 0, --Ktmp;
}
int main() {
#ifdef Qrsikno
	freopen("i.in","r",stdin);
	freopen("i.out","w",stdout);
#endif
	H = read(), W = read();
	rep(i, 1, H) {
		rep(j, 1, W) {
			char ch = getchar();
			if(ch == '#') ap[i][j] = 1, ++l_ans;
			if(ch == '.') ap[i][j] = 0;
		}
		getchar();
	}
	dfs(1, 1);
	puts(flag ? "Possible" : "Impossible");
	return 0;
}
