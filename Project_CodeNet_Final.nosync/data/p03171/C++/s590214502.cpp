#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const ll N = 3e3 + 1;
ll n,k;
ll arr[N][N];
bool kek[N][N];
ll a[N];
ll recurs(ll l = 0 ,ll r = n - 1){
	if(l == r){
		arr[l][r] = a[l];
		return a[l];	
	}
	if(kek[l][r])return arr[l][r];
	kek[l][r] = 1;
	arr[l][r] = max(a[l] - recurs(l + 1,r),a[r] - recurs(l,r - 1));
	return arr[l][r];
}

int main() {
	speed;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	recurs();
	cout << arr[0][n - 1];
}
/*
Timus : 288471KD
Atcoder : Zhabka
Codeforces : Zhabka
mail : dzhon.snoudin@mail.ru
*/

