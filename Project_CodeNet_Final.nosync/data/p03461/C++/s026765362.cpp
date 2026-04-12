#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int A,B;
int d[11][11];
const int C = 101;
int S = 1 , T = 2 * C;
int N = T , M = 2 * (C-1) + C * C;
int e[C][C];

int main(){
	cin >> A >> B;
	repp(i,1,A+1) repp(j,1,B+1) cin >> d[i][j];
	repp(i,0,C) repp(j,0,C){
		repp(x,1,A+1) repp(y,1,B+1) e[i][j] = max(e[i][j] , d[x][y]-i*x-j*y);
	}
	repp(x,1,A+1) repp(y,1,B+1){
		int z = C;
		repp(i,0,C) repp(j,0,C) z = min(z,e[i][j]+i*x+j*y);
		if(z != d[x][y]) return cout << "Impossible" << endl , 0;
	}
	cout << "Possible" << endl;
	cout << N << ' ' << M << endl;
	repp(i,1,C){
		cout << i << ' ' << i+1 << " X" << endl;
		cout << C+i << ' ' << C+i+1 << " Y" << endl;
	}
	repp(i,0,C) repp(j,0,C) cout << i+1 << ' ' << N-j << ' ' << e[i][j] << endl;
	cout << S << ' ' << T << endl;
	return 0;
}
