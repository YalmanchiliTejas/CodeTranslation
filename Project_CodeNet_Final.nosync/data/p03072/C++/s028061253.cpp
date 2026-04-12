#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int h[n];
	for(int i=0;i<n;i++){
		cin >> h[i];
	}
	// keisan
	int ans = 1;
	int highest = h[0];
	for(int i=1;i<n;i++){
		if(h[i] >= highest){
			ans++;
			highest = max(highest,h[i]);
		}
	}
	// syutsuryoku
	cout << ans << endl;
}