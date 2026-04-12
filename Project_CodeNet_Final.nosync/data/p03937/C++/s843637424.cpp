// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=10;

int n,m; char s[N][N];

void GG() { puts("Impossible"); exit(0); }

int main() {
	n=read(),m=read();
	for (int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for (int i=1;i<n;++i)
		for (int j=1;j<m;++j) {
			if (s[i][j]=='#'&&s[i][j+1]=='#'&&s[i+1][j]=='#') GG();
			if (s[i][j+1]=='#'&&s[i+1][j]=='#'&&s[i+1][j+1]=='#') GG();
		}
	puts("Possible");
	return 0;
}