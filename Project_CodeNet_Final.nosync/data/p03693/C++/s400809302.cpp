#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(a,b) a^=b^=a^=b
#define lb(x) ((x)&(-(x)))
#define inf 0x3f3f3f3f
#define N 500010
using namespace std;
typedef long long ll;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if((a*100+b*10+c)%4)puts("NO");
	else puts("YES");
	return 0;
}