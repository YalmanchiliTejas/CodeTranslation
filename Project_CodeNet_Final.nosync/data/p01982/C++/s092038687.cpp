#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll MOD = 1e9+7;

int main(){
  int n,l,r;
  while(cin>>n>>l>>r,n){
	int sum=0;
	int a[55];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=l;i<=r;i++){
	  a[n]=i;
	  for(int j=0;j<=n;j++){
		if(i%a[j]==0){
		  if(j%2==0)sum++;
		  break;
		}
	  }
	}
	cout<<sum<<endl;
  }
  return 0;
}

