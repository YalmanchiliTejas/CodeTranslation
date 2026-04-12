#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
	
	vector<ll> vec1;
	vector<ll> vec2;

	
	ll n;
	while (cin>>n){
		vec1.clear();
		vec2.clear();
		ll a[n];
		for (ll i = 0;i<n;i++){
			cin>>a[i];
			
		}
		for (ll i =0;i<n;i++){
		
			if (i%2==0){
				vec1.push_back(a[i]);
				
			}else {
				vec2.push_back(a[i]);
			}
			
			
		}
		if (n%2==0){
			for (ll i= vec2.size()-1;i>=0;i--){
				cout<<vec2[i]<<" ";
				
			}
			for (ll i= 0;i<vec1.size();i++){
				cout<<vec1[i]<<" ";
				
			}
			
		}else {
			for (ll i= vec1.size()-1;i>=0;i--){
				cout<<vec1[i]<<" ";
				
			}
			for (ll i= 0;i<vec2.size();i++){
				cout<<vec2[i]<<" ";
				
			}
			
		}
		cout<<endl;
	}
	
	return 0;
} 