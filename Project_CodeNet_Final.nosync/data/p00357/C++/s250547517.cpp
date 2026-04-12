#include<bits/stdc++.h>
using namespace std;
int d[300000];
int main(void){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> d[i];
	int p = d[0] / 10, flg = 1;
	if(p > 0){
		for(int i = 1; i < n - 1; i++){
			p--;
			p = max(p, d[i] / 10);
			if(p <= 0){
				flg = 0;
				break;
			}
		}
	}
	else flg = 0;
	if(flg == 1){
		p = d[n - 1] / 10;
		if(p > 0){
			for(int i = n - 2; i >= 1; i--){
				p--;
				p = max(p, d[i] / 10);
				if(p <= 0){
					flg = 0;
					break;
				}
			}
		}
		else flg = 0;
	}
	if(flg == 1) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
