#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int where[maxn], to[maxn], can[maxn], a[maxn], b[maxn];
int main(){
	where[0] = 1;
	int n, q; cin >> n >> q;
	for(int i = 1; i <= q; i++) cin >> a[i] >> b[i];
	for(int i = 1; i <= q; i++){
		where[i] = where[i - 1];
		if(where[i] == a[i] || where[i] == b[i])
			where[i] ^= a[i] ^ b[i];
	}
	for(int i = 1; i <= n; i++) to[i] = i;
	for(int i = q; i >= 0; i--){
		int w = where[i];
		if(w) can[to[w - 1]] = 1;
		if(w + 1 <= n) can[to[w + 1]] = 1;
		swap(to[a[i]], to[b[i]]);
	}
	can[where[q]] = 1;
	int s = 0;
	for(int i = 1; i <= n; i++) s += can[i];
	cout << s << endl;
	return 0;
}
