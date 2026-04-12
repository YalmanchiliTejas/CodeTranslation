#include <stdio.h>
#include <cctype>
#include <limits.h>
#include <math.h>
#include <complex>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) static_cast<bitset<16> >(x);
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))

const int INF = 1e9;
const double EPS = 1e-8;
const double PI = 3.14159;
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
/* struct P {
	int x, y, n;
	P(int n, int x, int y):n(n), x(x), y(y){}
	P(){}
}; */


/** Problem1135 : Ohgas' Fortune **/
int main()
{
	int M; cin>>M;
	rep(i, M) {
		int A, B, N;
		cin>>A>>B>>N;
		int ans = 0;
		rep(j, N) {
			int t; double r, s;
			int tA = A, tmp=0;
			cin>>t>>r>>s;
			rep(k, B) {
				if (t) {
					tA *= (1+r);
					tA -= s;
				} else {
					tmp += tA*r;
					tA -= s;
				}
			}
			ans = max(ans, tmp+tA);
		}
		cout << ans << endl;
	}
}