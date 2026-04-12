#include <iostream>

using namespace std;
int main(){
	int i,j,n,h[30],cnt = 1;
	cin >> n;
	for(i=0;i<n;i++) cin >> h[i];
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(h[j]>h[i]) break;
			if(j==i-1) cnt++;
		}
	}
	cout << cnt << endl;
}