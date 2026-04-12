#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007

map<string, int> m;




int main()
{
	FAST;
	ll n, m;
	cin >> n >> m;
	char a[n+4][m+5];
	bool v[n + 5];
	memset(v, false, sizeof(v));
	bool f[m + 4];
	memset(f, false, sizeof(f));
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <=m; j ++){
			cin >> a[i][j];
		}
	}
	for(ll i = 1; i <= n; i ++){
		bool x = false;
		for(ll j = 1; j <=m; j ++){
			if(a[i][j] == '#'){
				x = true;
				break;
			}
		}
		v[i] = x;
	}
	for(ll i = 1; i <= m; i ++){
		bool x = false;
		for(ll j = 1; j <= n; j ++){
			if(a[j][i] == '#'){
				x = true;
				break;
			}
		}
		f[i] = x;
	}
	for(ll i = 1; i <= n; i++){
		if(v[i]){
			for(ll j = 1; j <= m; j ++){
				if(f[j]){
					cout << a[i][j] ;
				}
			}
			cout << endl;
		}
		
	}
	return 0;
}