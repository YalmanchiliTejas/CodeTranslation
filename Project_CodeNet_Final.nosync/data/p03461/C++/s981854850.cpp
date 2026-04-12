#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
/////////////////////

int const N = 41;
int const INF = 1e9 + 41;

int a, b;
int d[N][N], w[N][N];

struct Edge{
	int x, y, c;
	bool f;
	Edge(){};
	Edge(int x, int y, int c, bool f) :
		x(x), y(y), c(c), f(f) {};
};

vector<Edge> e;

void bad(){
	printf("Impossible\n");
	exit(0);
}

void pushedge(int x, int y, int c, bool f){
	e.pb(Edge(x, y, c, f));
}

void solve(){
	fi(1, 101){
		pushedge(i, i+1, 'X', false);
	}
	fi(102, 201){
		pushedge(i, i+1, 'Y', false);
	}
	fi(0, 101) fj(0, 101){
		int v = 0;
		int y = -1, x = -1;
		for(int i1=0;i1<a;++i1) for(int j1=0;j1<b;++j1){
			int c = d[i1][j1] - (i1 + 1) * i - (j1 + 1) * j;
			if(v < c){
				v = c;
				y = i1;
				x = j1;
			}
		}
		int v0 = INF;
		for(int i1=0;i1<a;++i1) for(int j1=0;j1<b;++j1){
			if(w[i1][j1]) continue;
			int c = (i1 + 1) * i + (j1 + 1) * j + v;
			int v1 = d[i1][j1] - (i1 + 1) * i - (j1 + 1) * j;
			if(c <= d[i1][j1]){
				if(v0 > v1){
					v0 = v1;
				}
			}
		}
		if(v0 < INF){
			pushedge(1+i, 201-j, v0, true);
			for(int i1=0;i1<a;++i1) for(int j1=0;j1<b;++j1){
				if(w[i1][j1]) continue;
				int c = (i1 + 1) * i + (j1 + 1) * j + v;
				int v1 = d[i1][j1] - (i1 + 1) * i - (j1 + 1) * j;
				if(c <= d[i1][j1]){
					if(v0 == v1){
						w[i1][j1] = 1;
					}
				}
			}
			//cerr << 1+i << " " << 201-j << " " << y1 << " " << x1 << " " << v0 << endl;
		}
	}
	fi(0, a) fj(0, b) if(!w[i][j]) bad();
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d %d",&a,&b);
	fi(0, a) fj(0, b) scanf("%d",&d[i][j]);

	solve();

	printf("Possible\n");
	printf("201 %d\n",sz(e));
	fi(0, sz(e)){
		if(e[i].f) printf("%d %d %d\n",e[i].x,e[i].y,e[i].c);
		else printf("%d %d %c\n",e[i].x,e[i].y,(char)e[i].c);
	}
	printf("1 201\n");

	return 0;
}