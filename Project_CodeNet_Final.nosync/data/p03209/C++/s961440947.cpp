#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
int n;
ULL x;
ULL pat[52];
ULL siz[52];

int main(){
    //freopen("in.txt", "r", stdin);
	cin >> n;
	pat[0] = 1;
	siz[0] = 1;
	for(int i = 1; i <= n+1; ++i){
		pat[i] = pat[i-1]*2 + 1LL;
		siz[i] = siz[i-1]*2 + 3LL;
	}
	cin >> x;
	ULL ans = 0;
	for(int i = n; i >= 0; --i){
		if(x == 0) break;
		if(x == siz[i]){
			ans += pat[i];
			break;
		}
		if(x == 1){
			break;
		}
		if(x <= 1ll + siz[i-1]){
			x--;
		}else{
			ans += 1ll + pat[i-1];
			x -= 1ll + siz[i-1] + 1ll;
		}
	}
	cout << ans << endl;
	return 0;
}
