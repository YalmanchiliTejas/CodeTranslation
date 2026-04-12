#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 1<<30
using namespace std;
int n,cnt[30][100],m;
char s[100];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%s",s);
		for (int j=0;j<strlen(s);j++)
			cnt[s[j]-'a'+1][i]++;
	}
	for (int i=1;i<=26;i++) {
		m=INF;
		for (int j=1;j<=n;j++)
			m=min(m,cnt[i][j]);
		for (int j=1;j<=m;j++)
			printf("%c",i+'a'-1);
	}
	printf("\n");
	return 0;
}