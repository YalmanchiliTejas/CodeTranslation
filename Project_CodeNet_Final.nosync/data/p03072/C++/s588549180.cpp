#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int h[n];
	for(int i=0; i<n; i++) cin >> h[i];
	
	int ans=0;
	for(int i=0; i<n; i++){
		bool flag=true;
		for(int j=0; j<i; j++){
			if(h[j]>h[i]){ //自分より高い山があったらfalse
				flag=false;
				break;
			}
		}
		if(flag) ans++; //自分より高い山がない=true
	}
	cout << ans << endl;
}