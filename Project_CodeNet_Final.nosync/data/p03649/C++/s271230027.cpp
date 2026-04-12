#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <math.h>
#include <queue>
#include <map>
using namespace std;
typedef long long int ll; 

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	ll n; cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	ll res=0;
	while(1){
		ll sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i]/n;
		}
		if(sum==0)break;
		res+=sum;
		for(int i=0;i<n;i++){
			a[i]=(a[i]%n)+(sum-a[i]/n);
		}
	}
	cout << res << endl;
}