#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,ans = 0,sea = 0 ; cin >> N;
	for(int i = 0 ; i < N ; i++){
		int k; cin >> k;
		if(k >= sea){
			ans++;
			sea = k;
		}
	}
	cout << ans << endl;
}