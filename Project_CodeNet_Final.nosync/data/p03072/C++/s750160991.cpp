#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,a,ma=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>=ma){
			ans++;
			ma=a;
		}		
	}
	cout<<ans<<endl;
	return 0;
}