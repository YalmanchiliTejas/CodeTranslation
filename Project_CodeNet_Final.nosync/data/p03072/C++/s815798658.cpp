#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n; cin >> n;
	int ans=1, tmp_max=0;
	cin >> tmp_max;
	for(int i=1; i<n; i++){
		int h; cin >> h;
		if(tmp_max <= h){
			ans++;
			tmp_max = h;
		}
	}

	cout << ans << endl;

	return 0;
}