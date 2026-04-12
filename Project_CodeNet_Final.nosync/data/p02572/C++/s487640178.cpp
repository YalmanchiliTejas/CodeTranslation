#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int

const ll M=1e9+7;

ll mod(ll n){
	return (n%M + M)%M;	
}
ll add(ll a, ll b){
	return mod(mod(a)+mod(b));
}

ll mul(ll a, ll b){
	return mod(mod(a)*mod(b));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
    int t;
  	t=1;


    while(t--){
    	int n;
    	cin>>n;

    	vector<int> data(n);
    	for(int i=0;i<n;i++)
    		cin>>data[i];

    	vector<ll> suffix(n);
    	suffix[n-1]=data[n-1];

    	for(int i=n-2;i>=0;i--)
    		suffix[i]=data[i]+suffix[i+1];

    	ll ans=0;
    	for(int i=0;i<n-1;i++)
    		ans=add(ans,mul(data[i],suffix[i+1]));
    	
    	cout<<ans<<endl;
    }
    return 0;
}