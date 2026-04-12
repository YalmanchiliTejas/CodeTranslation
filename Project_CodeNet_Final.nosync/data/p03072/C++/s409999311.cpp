#include<bits/stdc++.h>
using namespace std;
int n,h[25],ans = 1;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> h[i];
	for(int i = 2;i <= n;i++){
		int yes = true;
		for(int j = 1;j < i;j++)
			if (h[j] > h[i]){
				yes = false;
				break;
			}
		if(yes)
			ans++;
	}
	cout << ans << endl;
	return 0;
}


