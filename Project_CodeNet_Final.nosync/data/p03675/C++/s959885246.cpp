#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,x,y) for(int i=((int)x);i<=((int)y);i++)
#define Dep(i,y,x) for(int i=((int)y);i>=((int)x);i--)
#define Rep(i,x) for (int y,i=head[x];i;i=E[i].nxt)
using namespace std;

const int inf=1000000009;

typedef double db;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;

int rd() {
	char c=getchar(); int t=0,f=1;
	while (!isdigit(c)) f=(c=='-')?-1:1,c=getchar();
	while (isdigit(c)) t=t*10+c-48,c=getchar(); return t*f;
}
void wt(int x) {
	if (x<0) putchar('-'),wt(-x);
	else { if (x>9) wt(x/10); putchar(x%10+48); }
}

#include<deque>

deque<int>Q;
deque<int>::iterator it;

int n;

int main() {
	n=rd();
	For (i,1,n) {
		if (i&1) Q.push_back(rd());
		else Q.push_front(rd());
	}
	if (n%2==1) reverse(Q.begin(),Q.end());
	for (it=Q.begin();it!=Q.end();it++)
		printf("%d ",*it);
}




