#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int h, w;
char M[10][10];

int main(){
	scanf("%d %d", &h, &w);
	FWD(i,0,h) scanf("%s", M[i]);	
	int x = 0, y = 0;
	M[x][y] = '.';
	while(x != h-1 || y != w-1){
		if(M[x+1][y] == '#'){
			++x;
		}else if(M[x][y+1] == '#'){
			++y;
		}else{
			break;
		}
		M[x][y] = '.';
	}
	FWD(i,0,h)
		FWD(j,0,w)
			if(M[i][j] == '#'){
				printf("Impossible\n");
				return 0;
			}
	printf("Possible\n");
	return 0;
}
