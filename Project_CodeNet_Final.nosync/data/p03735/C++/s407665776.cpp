#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;
const int oo=(1<<30)-1;

pii A[2*N];
int vis[N];
int n,x,y,c,mnx=oo,mxx=-oo,mny=oo,mxy=-oo,tmp;
ll ans;

int main(){
	n=IN();
	For(i,1,n+1){
		x=IN(),y=IN();
		if (x>y) swap(x,y);
		A[++c]=mp(x,i);
		A[++c]=mp(y,i);
		mnx=min(mnx,x);
		mxx=max(mxx,x);
		mny=min(mny,y);
		mxy=max(mxy,y);
	}
	ans=1ll*(mxx-mnx)*(mxy-mny);
	sort(A+1,A+c+1);
	for (int i=1,j=0;i<=c;i++){
		while (j+1<=c&&tmp!=n){
			if (++vis[A[++j].se]==1) tmp++;
		}
		if (tmp==n){
			ans=min(ans,1ll*(mxy-mnx)*(A[j].fi-A[i].fi));
		}
		if (--vis[A[i].se]==0) tmp--;
	}
	cout<<ans<<endl;
}