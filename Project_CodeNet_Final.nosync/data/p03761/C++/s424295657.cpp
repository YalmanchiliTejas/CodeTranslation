#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
int abs(int x){return x>0?x:-x;}
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
	int n;
	cin >> n;
	string s[n];
	int a[26];
	REP(i, 26) a[i] = 1000;
	REP(i, n){
		int b[26] = {};
		cin >> s[i];
		REP(j, (int)s[i].size()) b[(int)(s[i][j] - 'a')]++;
		REP(k, 26){
			a[k] = min(a[k], b[k]);
		}
	}

	REP(i, 26){
		if (a[i] != 1000){
			while (a[i]){
				cout << (char)(i + 'a');
				a[i]--;
			}
		}
	}
	
	cout << endl;
}
