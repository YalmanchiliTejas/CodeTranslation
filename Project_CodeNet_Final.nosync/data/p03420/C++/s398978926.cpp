#include "bits/stdc++.h"
using namespace std;

int main(){
	long long int n,k;
	cin>>n>>k;
	
	long long int ans=0;
	
	if(k==0){
		cout<<n*n<<endl;
		return 0;
	}
	
	for(int i=k+1;i<=n;i++){
		long long int tmp;
		tmp=n/i;
		ans+=tmp*(i-k);
		long long int tmp2=(n%i)-k+1;
		if(tmp2<0)tmp2=0;
		ans+=tmp2;
	}
	cout<<ans<<endl;
	
}