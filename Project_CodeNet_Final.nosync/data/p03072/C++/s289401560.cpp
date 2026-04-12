#include <iostream>
using namespace std;

int main(){
	int n,a[200];
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	int max=a[1],ans=1;
	for (int i=2;i<=n;i++){
		if (a[i]>=max) {
			ans++ ;
			max=a[i];
		}
	}
	cout << ans;
}