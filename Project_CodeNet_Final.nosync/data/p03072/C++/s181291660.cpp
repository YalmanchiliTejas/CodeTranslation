#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,i,j,count;
  cin>>n;
  	vector<ll> h(n);
  	for(i=0;i<n;i++){
      	cin>>h[i];
    }

  	ll ans=1;
  
  	for(i=1;i<n;i++){
      count=0;
      for(j=0;j<i;j++){
		if(h[i]>=h[j]){
          count++;
        }
      }
  		if(count==i){
          ans++;
        }
    }
  	
  cout<<ans<<endl;

}

