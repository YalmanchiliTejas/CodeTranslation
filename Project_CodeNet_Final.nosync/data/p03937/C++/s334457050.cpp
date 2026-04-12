#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#define MOD 1000000007LL
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	string a[h];
	for(int i = 0; i < h; i++) cin >> a[i];
	int x = 0, y = 0;
	int ans = 1;
	int count = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(a[i][j] == '#') count++;
		}
	}
	if(count != (h + w - 1)) cout << "Impossible" << endl;
	else cout << "Possible" << endl;
	return 0;
}
