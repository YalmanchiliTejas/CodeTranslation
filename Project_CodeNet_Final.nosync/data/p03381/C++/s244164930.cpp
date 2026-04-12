#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 2e5 + 10;
int rk[maxn] , ans[maxn];
int n;
int a[maxn];

bool cmp(int x , int y){
	return a[x] < a[y];
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1 ; i <= n ; ++ i)
		cin >> a[i];
	for(int i = 1 ; i <= n ; ++ i)
		rk[i] = i;
	sort(rk + 1 , rk + n + 1 , cmp);
	for(int i = 1 ; i <= n / 2 ; ++ i)
		ans[rk[i]] = a[rk[n / 2 + 1]];
	for(int i = n / 2 + 1 ; i <= n ; ++ i)
		ans[rk[i]] = a[rk[n / 2]];
	for(int i = 1 ; i <= n ; ++ i)
		cout << ans[i] << endl; 
	return 0;
}