#include<bits/stdc++.h>
#define maxn 3200
using namespace std;
typedef long long LL;
LL f[maxn][maxn];
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for(int i = 1; i <= N; i += 1) cin >> a[i];
	for(int L = 0; L < N; L += 1)
		for(int i = 1; i + L <= N; i += 1){
			f[i][L] = L ? max(- f[i + 1][L - 1] + a[i], - f[i][L - 1] + a[i + L]) : a[i];
		}
	cout << f[1][N - 1];
} 