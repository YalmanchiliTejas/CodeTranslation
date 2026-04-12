#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main(void) {
	int n;
	long long ans=0;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0; i<n; i++){
		if(n%2==0){
			if(i+1==n-1-i){
				ans+=a[n-1-i]-a[i];
				break;
			}else {
				ans+=2*(a[n-1-i]-a[i]);
			}
		}else {
			if(i+2==n-1-i){
				ans+=max(2*a[i+2]-a[i+1]-a[i],a[i+2]+a[i+1]-a[i]*2);
				break;
			}else {
				ans+=2*(a[n-1-i]-a[i]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}