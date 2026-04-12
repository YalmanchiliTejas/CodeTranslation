#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e3 + 5;

int mx[MAXN][MAXN];
int d[MAXN][MAXN];
int used[MAXN][MAXN];

void solve(){
	int A, B;
	scanf("%d%d", &A, &B);
	REPN(i, 1, A){
		REPN(j, 1, B){
			scanf("%d", &d[i][j]);
		}
	}
	int lim = 100;
	REPN(i, 0, lim){
		REPN(j, 0, lim){
			REPN(k, 1, A){
				REPN(l, 1, B){
					int delta = d[k][l] - (i * k + j * l);
					mx[i][j] = max(mx[i][j], delta);
				}
			}
			REPN(k, 1, A){
				REPN(l, 1, B){
					int delta = d[k][l] - (i * k + j * l);
					if (delta == mx[i][j]){
						//printf("%d %d %d %d %d\n", i, j, k, l, d[k][l]);
						used[k][l] = 1;
					}
					/*if (k == 1 && l == 1){
						printf("%d %d %d %d\n", i, j, i * k + j * l + mx[i][j], d[1][1]);
					}*/
				}
			}
		}
	}
	
	int good = 1;
	REPN(k, 1, A){
		REPN(l, 1, B){
			//printf("%d %d %d\n", k, l, used[k][l]);
			good &= used[k][l];
		}
	}
	
	if (!good){
		printf("Impossible\n");
		return;
	}
	printf("Possible\n");
	int n = lim + lim + 2;
	printf("%d %d\n", n, (lim + 1) * (lim + 1) + lim + lim);
	REPN(i, 1, lim){
		printf("%d %d X\n", i, i + 1);
	}
	REPN(i, 1, lim){
		printf("%d %d Y\n", lim + 1 + i, lim + 1 + i + 1);
	}
	REPN(i, 0, lim){
		REPN(j, 0, lim){
			printf("%d %d %d\n", i + 1, n - j, mx[i][j]);
		}
	}
	printf("%d %d\n", 1, n);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
