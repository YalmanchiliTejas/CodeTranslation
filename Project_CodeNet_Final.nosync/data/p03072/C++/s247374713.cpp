#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, ans = 1;
	cin >> N;
	int H[N];
	for(int i = 0; i < N; i++)
		cin >> H[i];
	for(int i = 1; i < N; i++){
		int b = 1;
		for(int j = 0; j < i; j++){
			if(H[i] < H[j])
				b *= 0;
		}
		if(b)
			ans++;
	}
	cout << ans << endl;
	return 0;
}