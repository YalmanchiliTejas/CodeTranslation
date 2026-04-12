#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
int main(){
	ll n,k;
	cin>>n>>k;
	ll rev = 0;
	for(int i=1;i<=n;i++){
		if(i<=k){
			rev += (n+1);
		}
		else{
			ll sh = (n+1)/i;
			ll am = (n+1)%i;
			rev += k * sh;
			rev += min(am,k);
		}
	}
	if(k==0)rev = n;
	cout<<n*(n+1)-rev<<endl;
	return 0;
}