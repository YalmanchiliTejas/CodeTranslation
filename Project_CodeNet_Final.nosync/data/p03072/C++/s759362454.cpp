#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int hmax = 0;
	int ans = 0;
	for(int i=0; i<n; i++){
		int h;
		cin >> h;
		if(hmax <= h) ans++;
		hmax = max(hmax, h);
	}
	cout << ans << endl;
	return 0;
}