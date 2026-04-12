#include <iostream>

using namespace std;
long long a[100010],ans = 0;
int main(){
	int i,j,n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	for(i=1;i<n;i++){
		long long sum = 0;
		for(j=0;j<n-1;j+=i){
			sum += (a[j] + a[n - 1 - j]);
			if(i>=n - 1 - j) break;
			if((n-1)%i==0 && j>n/2 - 1) break;
			ans = max(ans,sum);
		}
	}
	cout << ans << endl;
}
