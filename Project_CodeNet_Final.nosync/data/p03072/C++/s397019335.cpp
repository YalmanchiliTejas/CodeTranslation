#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int h[30];
	for(int i = 0; i < n; ++i) cin >> h[i];
	int maxv = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(h[i] >= maxv){
			cnt++;
			maxv = h[i];
		}
	}
	cout << cnt << endl;
}
