#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N], b[N], tot;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(int i = n-1; i >= 0; i -= 2){
		b[tot ++] = a[i];
	}
	for(int i = n&1; i < n; i += 2){
		b[tot ++] = a[i];
	}
	for(int i = 0; i < n; ++ i){
		printf("%d%c", b[i], i == n-1 ? '\n' : ' ');
	}
}
