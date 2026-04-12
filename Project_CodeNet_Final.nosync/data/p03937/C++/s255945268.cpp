#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
	ll n, m; cin >> n >> m;
	char arr[n][m];
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < m; ++j){
			cin >> arr[i][j];
		}
	}
	for(ll i = 0; i < n; ++i){
		for(ll j = 1; j < m - 1; ++j){
			if(arr[i][j] == '.' && arr[i][j - 1] == '#' && arr[i][j + 1] == '#'){
				cout << "Impossible";
				return 0;
			}
		}
	}
	ll last = 0;
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < m; ++j){
			if(arr[i][j] == '#'){
				if(last > j){
					cout << "Impossible";
					return 0;
				}
				last = j;
			}
		}
	}
	cout << "Possible";
    return 0;
}
