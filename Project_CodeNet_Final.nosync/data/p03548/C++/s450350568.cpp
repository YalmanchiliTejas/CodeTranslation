#include<bits/stdc++.h>

using namespace std;

int main(){

	int X, Y, Z;
	cin >> X >> Y >> Z;

	int ans = 0;

	int now = 0;
	for (int i = 0;; i++){
		if (i % 2 == 0)
			now += Z;

		else{
			now += Y;
			ans++;
		}
		if (now > X){
			ans--;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}