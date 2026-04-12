#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;


inline void boost () {
	ios_base::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
}


bool comp(ll a, ll b){
	return a >= b;
}

void solve(){
	int n, m, cnt = 0;
	char a[15][15];
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(a[i][j] == '#'){
				cnt++;
			}
		}
	}
	
	if(cnt != n + m - 1){
		cout << "Impossible";
		return;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i + 1][j] == '#' && a[i][j + 1] == '#'){
				cout << "Impossible";
				return;
			}
		}
	}
		cout << "Possible";
}


int main() {    
 boost();
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}
