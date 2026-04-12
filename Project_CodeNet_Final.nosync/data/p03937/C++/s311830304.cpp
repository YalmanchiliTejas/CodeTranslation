#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<ll, int> P;

int main(){
	int H, W, ans = 0; cin >> H >> W;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			char c; cin >> c;
			if(c == '#') ans++;
		}
	}
	if(ans == H+W-1) cout << "Possible" << "\n";
	else cout << "Impossible" << "\n";
	return 0;
}
