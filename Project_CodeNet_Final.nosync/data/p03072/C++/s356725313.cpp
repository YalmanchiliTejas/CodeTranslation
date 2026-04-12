#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, maxi, a, ans = 1;
	ans = 1;
	cin >> n;
	cin >> a;
	maxi = a;
	for(int i = 1 ; i < n ; i++){
		cin >> a;
		if(a >= maxi){
			ans++;
			maxi = a;
		}
	}
	cout << ans << endl;
	return 0;
}