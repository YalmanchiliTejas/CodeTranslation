#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	unsigned long long n;
	// nyuryoku
	cin >> n;
	unsigned long long w = 1e9 + 7;
	unsigned long long a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	unsigned long long s[n-1];
	for(int i=n-2;i >= 0;i--){
		if(i == n-2){
			s[i] = a[n-1];
		}else{
			s[i] = (s[i+1] + a[i+1])%w;
		}
	}
	// keisan
	unsigned long long ans = 0;
	for(int i=0;i<n-1;i++){
		ans = (ans + a[i]*s[i]%w)%w;
	}
	// syutsuryoku
	cout << ans << endl;
}