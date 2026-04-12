#include "bits/stdc++.h"
using namespace std;
#define maxn 501
#define rep(i,n) for(int i=0; i<int(n); ++i)
#define pb push_back
#define mp make_pair
#define mod 1000000007

int n;
long long a[100];
long long k;

bool is_tail(){
	return 0;
}

void do_one(int j){
	a[j] -= n + 1;
	rep(i, n) a[i] ++;
	k++;
}

void debug(){
	cout << k << endl;
	rep(i, n) cout << a[i] << ' '; cout << endl;
}
void solve(){
	cin >> n;
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	k = 0;
	//if (is_tail()) k += tail();
	//debug();
	//a[n] = n - 1;
	for(int i=1; i<n; ++i){
		long long diff = a[i - 1] - a[i];
		//cout << "d " << diff << endl;
		if (diff < n) continue;
		int delta = n + 1;
		//
		rep(j, i) a[j] -= (n - i + 1) * (diff / delta);
		for (int j = i; j < n; ++j) a[j] += i * (diff / delta);
		k += 1ll * i * (diff / delta);
		//
		while (a[0] - a[i] >= n){
			do_one(0);
			sort(a, a + n);
			reverse(a, a + n);
		}
		//debug();
	}
	if (a[n - 1] > n + n){
		k += 1ll * (a[n - 1] - (n + n)) * n;
		rep(i, n) a[i] -= a[n - 1] - (n + n);
	}
	while (true){
		sort(a, a + n);
		reverse(a, a + n);
		if (a[0] < n){
			cout << k;
			return;
		}
		do_one(0);
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    solve();
}