#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int h[n];
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	int mx = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(h[i] >= mx){
			ans++;
			mx = h[i];
		}
	}
	cout << ans;
}
