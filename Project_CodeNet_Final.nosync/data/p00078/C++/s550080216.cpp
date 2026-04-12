#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int maho[15][15];

int main() {
	int n;
	for(;n=in();){
		int x=n/2,y=n/2+1;
		int i;
		memset(maho,0,sizeof(maho));
		for(i=1;i<=n*n;i++){
			while(maho[y][x]){
				x--;y++;
				if(x==-1)x=n-1;
				if(y==n)y=0;
			}
			maho[y][x]=i;
			x++;y++;
			if(x==n)x=0;
			if(y==n)y=0;
		}
		int xx,yy;
		for(yy=0;yy<n;yy++){
			for(xx=0;xx<n;xx++){
				printf("%4d",maho[yy][xx]);
			}
			cout<<endl;
		}
	}
	return 0;
}