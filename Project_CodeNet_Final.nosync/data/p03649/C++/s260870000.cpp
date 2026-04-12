// 21:57 - 22:02
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lch (o << 1)
#define rch (o << 1 | 1)

typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pint;

const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;

ll s[N];

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	for(int i=1; i<=n; i++)
		cin >> s[i];
	
	ll ans = 0;
	bool f = 1;
	while(f){
		f = 0;
		for(int i=1; i<=n; i++){
			if(s[i] >= n){
				f = 1;
				ll d = (s[i] - (n - 1) + n - 1) / n;
				s[i] -= d * n;
				for(int j=1; j<=n; j++)
					if(i != j) s[j] += d;
				ans += d;
			}
		}
		if(!f) break;
	}

	cout << ans << endl;

	return 0;
}