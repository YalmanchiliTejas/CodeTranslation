#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n,x;
	cin >> n >> x;
	ll left=1;
	for(int i = 0; i < n; i++)left = left*2+3;
	ll ans=0;
	//cout << left << endl;
	left = left/2+1;
	while(1){
		if(x == left){
			ans+=left/2+1;
			break;
		}
		if(x == 1){
			break;
		}
		if(x == left*2-1){
			ans+=left;
			break;
		}
		if(x > left){
			ans+=left/2+1;
			x-=left;
			left = (left-2)/2+1;
		}
		else{
			x--;
			left = (left-2)/2+1;
		}
	}
	cout << ans << endl;
    return 0;
}