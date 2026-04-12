#include<bits/stdc++.h>

using namespace std;

int main(){
	int X, Y, Z; cin >> X >> Y >> Z;
	int ans = 0;
	int now = Z;
	while(1){
		if(now + Y + Z <= X){
			now += Y + Z;
			ans++;
		}else{
			break;
		}
	}
	cout << ans << endl;
}