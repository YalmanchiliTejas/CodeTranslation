#include <bits/stdc++.h>
using namespace std ;

int main() {
	int N;
	cin >> N;
	vector <int> height(N);
	for(int i = 0; i < N; i++) {
		cin >>height[i];
	}
	int max = 0;
	int ans = 0;
	for(int i = 0;i < N;i++){
	if(max <= height[i]){
		max = height[i];
        ans++;
	}
	}
cout << ans<< endl;
}