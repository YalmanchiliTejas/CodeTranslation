#include <bits/stdc++.h>
using namespace std;

int main(){
	int S[1005];
	int n,sum;
	while(1){
		cin>>n;
		if(n==0) break;
		sum=0;
		for(int i=0;i<n;i++) cin>>S[i];
		sort(S,S+n);
		for(int i=1;i<n-1;i++) sum+=S[i];
		cout<<sum/(n-2)<<endl;
	}
	return 0;
}
