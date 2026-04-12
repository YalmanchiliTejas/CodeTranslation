#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
		cin >> N;
		vector<int> H(N);
		for(int i = 0; i < N; ++i) cin >> H[i];

		int cnt = 0;

		for(int i = 0; i < N; ++i) {
			bool flag = false;
			for(int k = 0; k < i; ++k) {
				if(H[k] <= H[i] && flag == false) {
				} else {
					flag = true;
				}
			}

			if(flag == false) {
				cnt++;
			}
		}

		cout << cnt << endl;
}
