#include <iostream>

using namespace std;
int main(){
	long long i,n,a[51],b[51],ans=0,c;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	while(true){
		c = 0;
		for(i=0;i<n;i++){
			b[i] = 0;
			if(a[i]>=n){
				b[i] = (a[i]-n)/n + 1;
				c += b[i];
			}
		}
		ans += c;
		if(c==0){
			break;
		}
		for(i=0;i<n;i++){
			a[i] = a[i] - b[i]*n + c-b[i];
		}
	}
	cout << ans << endl;
}
