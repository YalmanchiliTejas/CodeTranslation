#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,i,c[30],max,ans=1;
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> c[i];
		if(i==1){
			max=c[i];
		} else {
			if(max<=c[i]){
				ans++;
				max=c[i];
			}
		}
	}
	cout << ans << endl;
	return 0;
}