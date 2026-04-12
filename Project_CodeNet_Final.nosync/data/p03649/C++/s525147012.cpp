#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
typedef long long int LL;

int n; LL seq[MAXN], ans, cnt;

void simulate(){
	int i;
	for(i = 1; i < n; ++ i) ++ seq[i];
	for(seq[i --] -= n; i && seq[i] > seq[i + 1]; -- i)
		swap(seq[i], seq[i + 1]);
}
int main(){
	int i, j;
	cin >> n;
	for(i = 1; i <= n; ++ i)
		cin >> seq[i];
	sort(seq + 1, seq + 1 + n);
	for(i = n; i && seq[n] - seq[i] <= n + 1; -- i) ;
	while(i){
		cnt = (seq[n] - seq[i] - n - 1) / (n + 1);
		ans += cnt * (n - i);
		for(j = 1; j <= i; ++ j)
			seq[j] += cnt * (n - i);
		for(; j <= n; ++ j)
			seq[j] -= cnt * (i + 1);
		while(seq[n] - seq[i] > n + 1)
			simulate(), ++ ans;
		while(i && seq[n] - seq[i] <= n + 1) -- i;
	}
	cnt = max(seq[1] - n + 1LL, 0LL);
	ans += cnt * n;
	for(j = 1; j <= n; ++ j)
		seq[j] -= cnt;
	while(seq[n] >= n)
		simulate(), ++ ans;
	cout << ans << endl;
	return 0;
}