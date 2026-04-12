#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	
	int n ,k;
	char s[10];
	cin >> n;
	REP(i, n)
		cin >> s[i];
	cin >> k;
	char c = s[k-1];
	REP(i, n){
		if(s[i] == c)
			cout << c;
		else
			cout << '*';
	}
	
	cout << '\n';
 
	return 0;
}