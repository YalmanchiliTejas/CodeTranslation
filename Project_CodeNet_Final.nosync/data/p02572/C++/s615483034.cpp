#include<bits/stdc++.h>
#define M_PI       3.14159265358979323846
#define Speed_UP  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define 	pb	push_back 
#define 	ff	first 
#define 	ss	second 
#define sz(x) (int)x.size()
#warning Remeber to change t
using namespace std;
typedef long long ll;
inline void setIO(string name="") {
	#ifndef ONLINE_JUDGE 
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
	#endif
	}
ll const M=1e9+7;
int main(){
	Speed_UP
	ll t;
	t=1;
	while(t--){
		ll n;
    cin>>n;
    ll arr[n];
    ll sum=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      sum+=arr[i];
      sum%=M;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
      sum-=(arr[i]%M);
      sum=(sum+M)%M;
      sum%=M;
      ans+=((arr[i]%M)*sum)%M;
      ans%=M;
    }
    cout<<ans;
		
		
		
	}





}
