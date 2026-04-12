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

int souchi[11][11];
int xx[]={1,-1,0,0,0};
int yy[]={0,0,1,-1,0};

void f(int a,int b){
	int i;
	for(i=0;i<5;i++){
		if(a+xx[i]<0||10<=a+xx[i]||b+yy[i]<0||10<=b+yy[i])continue;
		souchi[a+xx[i]][b+yy[i]]^=1;
	}
}

int main() {
	int n=in();
	int i;
	for(i=0;i<n;i++){
		int a,b;
		int tmp[11][11];
		int res[11][11];
		for(a=0;a<10;a++){
			for(b=0;b<10;b++){
				cin>>tmp[a][b];
			}
		}
		int bit;
		for(bit=0;bit<1<<10;bit++){
			for(a=0;a<10;a++){
				for(b=0;b<10;b++){
					souchi[a][b]=tmp[a][b];
					res[a][b]=0;
				}
			}
			for(b=0;b<10;b++){
				if(bit>>b&1){
					f(0,b);
					res[0][b]=1;
				}
			}
			for(a=0;a<9;a++){
				for(b=0;b<10;b++){
					if(souchi[a][b]){
						f(a+1,b);
						res[a+1][b]=1;
					}
				}
			}
			bool ok=true;
			for(b=0;b<10;b++){
				if(souchi[9][b])ok=false;
			}
			if(ok){
				for(a=0;a<10;a++){
					for(b=0;b<10;b++){
						cout<<res[a][b];
						if(b!=9)cout<<" ";
					}
					cout<<endl;
				}
			}
		}
	}
	return 0;
}