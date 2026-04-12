#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, ans = 0;
	cin >> N;
	int H[N];
	for(int i=0; i<N; i++) cin >> H[i];
	for(int i=0; i<N; i++){
		int f = 0;
		for(int j=0; j<i; j++){
			if(H[j] > H[i]) f = 1;
		}
		if(!f) ans++;
	}
	cout << ans << endl;
	return 0;
}
