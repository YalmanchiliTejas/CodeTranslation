#include<bits/stdc++.h>
#define ll long long
#define w cout 
#define e '\n'

using namespace std;

const int N = 1e6 + 5;
ll dd[3002][3002];

int main(){
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
	ll n;
	cin >> n;
	ll arr[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for(int L = n ;  L >= 1 ; L --) {
		for(int R = L ; R <= n ; R ++) {
			if(L == R) {
				dd[L][R] = arr[L];
			} else {
				dd[L][R] = max(arr[L] - dd[L + 1][R] , arr[R] - dd[L][R - 1]);
			}
		}
	}

	w << dd[1][n];

}