#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int bh,h;
	bh = 0;
	int ans = 0;
	for(int i = 0;i < n;i++){
		cin >> h;
		if(bh <= h)ans++;
		bh = max(bh,h);
	}
	cout << ans << endl;
	return 0;
}