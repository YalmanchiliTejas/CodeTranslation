#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int h, w;
	cin >> h >> w;
	string a[h];
	for(int i = 0; i < h; i++) cin >> a[i];
	int b = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			b += (a[i][j] == '#');
		}
	}
	cout << ((b == (h+w-1)) ? "Possible" : "Impossible") << endl;
}
