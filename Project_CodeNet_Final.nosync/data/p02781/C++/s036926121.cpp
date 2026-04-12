#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

long double a[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	
	string s;
	cin>>s;
	int k;
	cin>>k;
	int n = (int)s.size();
	if(k == 1){
		ll ans = (n-1)*9 + s[0]-'0';
		cout<<ans<<endl;
		return 0;
	}
	if(k == 2){
		ll ans = 0;
		for(int i=1;i<n-1;i++){
			ans += 9ll * (i*9);
		}
		
		ans += max(0,(s[0]-'0'-1) * (n-1) * 9);
		
		for(int i=1;i<n;i++){
			if(s[i] != '0'){
				
				ans += s[i]-'0';
				ans += max(0,(n-i-1)*9);
				
				break;
			}
		}
		
		cout<<ans<<endl;
		return 0;
	}
	
	ll ans = 0;
	for(int i=2;i<n-1;i++){
		ans += (i*(i-1))/2 * 9 * 9 * 9;
	}
	ans += max(0,(s[0]-'0'-1) * (n-1) * (n-2) / 2 * 9 * 9);
	for(int i=1;i<n;i++){
		if(s[i] != '0'){
			ans += max(0,(s[i]-'0'-1) * (n-i-1) * 9);
			ans += max(0,(n-i-1)*(n-i-2) / 2 * 9 * 9);
			for(int j=i+1;j<n;j++){
				if(s[j] != '0'){
					
					ans += s[j]-'0';
					ans += max(0,(n-j-1)*9);
					
					break;
				}
			}
			break;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
