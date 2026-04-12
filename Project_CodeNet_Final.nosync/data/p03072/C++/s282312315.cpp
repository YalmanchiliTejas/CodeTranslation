#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int heights[n];
	for(int i=0; i<n; i++) cin >> heights[i];
	int ans = 1; int mx = heights[0];
	for(int i=1; i<n; i++){
		if(max(heights[i],mx)==heights[i]){
			ans++;
			mx = heights[i];
		}
	}
	cout << ans;
	return 0;
}