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
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	REP(i, n) cin >> a[i];

	REP(i, n){
		bool flag = 1;
		REP(j, i){
			if (a[i] < a[j]) flag = 0;
		}
		if (flag) ans++;
	}

	cout << ans << endl;
}
