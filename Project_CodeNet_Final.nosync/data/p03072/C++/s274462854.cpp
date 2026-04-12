#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x
#define bit(n) (1<<(n))

#define rep(i,n) for (int i=0;i<(n);i++)
#define repp(i,n) for (int i=0;i<=(n);i++)

int main(){
	int n, h[1000], cnt=0;
	cin >> n;
	rep(i, n) cin >> h[i];

	rep(i, n){
		bool f = true;

		repp(j, i){
			if(h[j] > h[i])
				f = false;
		}

		if(f) ++cnt;
	}

	cout << cnt << endl;

	return 0;
}
