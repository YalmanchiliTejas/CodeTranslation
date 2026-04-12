#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9 +7;
int main(){


#ifndef ONLINE_JUDGE   
freopen("input.txt", "r", stdin); 
// freopen("output.txt", "w", stdout);    
#endif 
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);


ll n;
cin>>n;
ll a[n];
ll sum=0;
for(int i=0;i<n;i++){
	cin>>a[i];
	sum+=a[i];
}

ll sum1=0;

for(int i=0;i<n-1;i++){
	sum = sum - a[i];

	sum1 = sum1 + ((sum % mod) * (a[i] % mod)) % mod;
	sum1 = sum1 % mod;
}

cout<<sum1;

return 0;
}



