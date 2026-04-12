#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(){
	long long n;
	cin >> n;
	vector<long long > a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<long long> v(n);
	long long ans=0;
	while(1){
		long long s=0;
		for(int i=0;i<n;i++){
			v[i]=0;
		}
		for(int i=0;i<n;i++){
			if(a[i]>=n){
				v[i]=(a[i]-n+1)/n;
				a[i]-=n*v[i];
				if(a[i]>=n){
					a[i]-=n;
					v[i]+=1;
				}
				s+=v[i];
			}
		}
		if(s==0)break;
		for(int i=0;i<n;i++){
			a[i]+= s-v[i];
		}
		ans +=s;
	}
	cout << ans << endl;
	return 0;
}