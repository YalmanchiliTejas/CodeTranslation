#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define SORT(v, n) sort(v, v+n);
#define SSORT(v, n) sort(v, v+n, greater<int>())

int main(){
	int n;
	cin >> n;
	int h[n];
	int maxm = 0;
	int ans = 0;
	for(int i=0; i<n; i++) cin >> h[i];
	for(int i=0; i<n; i++) {
		if(h[i]>=maxm){
			maxm = h[i];
			ans++;
		}
	}
	cout << ans << endl;

}