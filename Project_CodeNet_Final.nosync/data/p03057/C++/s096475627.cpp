#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 200005;
const int mod = 1e9 + 7;

int n, m;
int f[MAXN];
char s[MAXN];
int sum[MAXN];

int main(){
	scanf("%d %d %s",&n,&m,s);
	for(int i=0; i<m; i++) if(s[i] == 'R') s[i] = 'A';
	if(s[0] == 'B'){
		for(int i=0; i<m; i++) s[i] = 'A' + 'B' - s[i];
	}
	if(count(s, s + m, 'B') == 0){
		f[0] = 1; f[1] = 2;
		for(int i=2; i<=n; i++){
			f[i] = f[i-1] + f[i-2];
			f[i] %= mod;
		}
		lint ret = f[n];
		if(n == 3) ret += mod - 1;
		else if(n >= 4) ret += mod - f[n - 4];
		ret %= mod;
		cout << ret << endl;
		return 0;
	}
	int alt = 1e9;
	int pref = 0;
	while(s[pref] == 'A') pref++;
	for(int i=0; i<m; i++){
		if(s[i] == 'B'){
			int e = i + 1;
			while(s[e] == 'A') e++;
			if(e == m) break;
			if(e > i + 1 && e % 2 == i % 2){
				alt = min(alt, e - i - 1);
			}
			i = e - 1;
		}
	}
	if(n % 2 == 1){
		puts("0");
		return 0;
	}
	int x = min(alt, pref + 1);
	f[0] = 1;
	sum[0] = 1;
	for(int i=1; i<=n/2; i++){
		f[i] = sum[i - 1];
		if(i >= (x + 3) / 2) f[i] += mod - sum[i - (x + 3) / 2];
		f[i] %= mod;
		sum[i] = (sum[i-1] + f[i]) % mod;
	}
	lint ret = 0;
	for(int i=0; i<n;i++){
		int len = n - 1 - x;
		if(n - 1 - x > n - 1 - i) continue;
		ret += sum[(n - 1 - i) / 2];
		if(len >= 1){
			ret += mod - sum[(len - 1) / 2];
		}
	}

	cout << ret % mod << endl;
}
