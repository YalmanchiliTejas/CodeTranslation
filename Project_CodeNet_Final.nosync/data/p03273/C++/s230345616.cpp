#include <bits/stdc++.h>
#define ll      long long
#define ld      long double
#define pb      push_back
#define mp      make_pair
#define all(x)  x.begin(),x.end()
#define ff      first
#define ss      second
#define pi      acos(-1.0)
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	ll n,m;
	cin >> n >> m;
	char a[n][m];
	vector <bool> vi(n);
	vector <bool> vj(m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		ll k1 = 0;
		ll k2 = 0;
		for (int j = 0; j < m; j++){
			if (a[i][j]=='#'){
				k1++;
			}
			else{
				k2++;
			}
		}
		if (k1 == 0){
			vi[i] = 1;
		}
	}
	for (int j = 0; j < m; j++){
		ll k1 = 0;
		ll k2 = 0;
		for (int i = 0; i < n; i++){
			if (a[i][j]=='#'){
				k1++;
			}
			else{
				k2++;
			}
		}
		if (k1 == 0){
			vj[j]=1;
		}
	}
	for (int i = 0; i < n; i++){
		if (!vi[i]){
			for (int j = 0; j < m; j++){
				if (!vj[j]){
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;

}