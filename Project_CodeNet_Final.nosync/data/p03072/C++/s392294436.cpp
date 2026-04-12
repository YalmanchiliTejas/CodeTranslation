#include<bits/stdc++.h>                                                   
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define rept(i,a,b) for(int i=a; i<b; i++)
#define ll long long
#define all(x) (x).begin(),(x).end()

int main() {
	int n;
	cin >> n;

	vector<int> h(n);
	rep(i, n){
		cin >> h[i];
	}

	int ans = 1;
	int buf = h[0];
	rept(i, 1, n){
		buf = max(buf, h[i]);
		if(buf <= h[i]){
			ans++;
		}
	}

	cout << ans << endl;

    return 0;
}

