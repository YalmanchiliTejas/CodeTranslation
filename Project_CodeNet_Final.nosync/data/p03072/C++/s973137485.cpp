#include<iostream>
using namespace std;
int main(){
	int n, h, pre, ans;
	pre = ans = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> h;
		if(pre <= h){
			ans++;
			pre = h;
		}
	}
	cout << ans << endl;
	return 0;
}