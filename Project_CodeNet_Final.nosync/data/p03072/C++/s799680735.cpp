#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <map>
 
using namespace std;
typedef long long ll;

ll ans,mn,mx;
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		mx=max(mx,a[i]);
		if(a[i] >= mx) ans++;
	}
	cout<<ans<<endl;
}