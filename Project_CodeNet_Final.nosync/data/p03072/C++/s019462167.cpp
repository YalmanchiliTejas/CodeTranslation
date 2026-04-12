#include<bits/stdc++.h>
using namespace std;

int main(void){

	int n;
	cin >> n;

	vector<int>h(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}

	int ans = 1;
	for(int i = 1; i < n; i++){
		bool canSee = false;

		if(h[i-1] <= h[i]){
			canSee = true;
			for(int j = 0; j < i; j++){
				if(h[j] > h[i]){
					canSee = false;
					break;
				}
			}
		}

		if(canSee) ans++;
	}
	cout << ans;
	
	return 0;
}