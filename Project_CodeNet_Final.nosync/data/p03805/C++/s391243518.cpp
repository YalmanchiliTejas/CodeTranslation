#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
int GCD(int a,int b){return b?GCD(b,a%b):a;}
int LCM(int a,int b){return (a*b)/GCD(a,b);}
int abs(int x){return x>0?x:-x;}
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
	int n, m;
	cin >> n >> m;
	if (m == 0){
		cout << 0 << endl;
		return 0;
	}
	int a[m], b[m];
	int p[n];
	REP(i, n){
		p[i] = i+1;
	}
	REP(i, m) cin >> a[i] >> b[i];

	int ans = 0;

	do {
		int res = 0;
		for (int i = 0; i < n-1; i++){
			for (int j = 0; j < m; j++){
				if ((p[i] == a[j] and p[i+1] == b[j]) or (p[i] == b[j] and p[i+1] == a[j])){
					res++;
					break;
				}
			}
		}

		if (res+1 == n) ans++;
	} while (next_permutation(p+1, p+n));

	cout << ans << endl;
}
