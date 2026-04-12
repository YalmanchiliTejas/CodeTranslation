#include <bits/stdc++.h>
using namespace std;

struct B{long long p,sum;};

int main(){
	long long n,x,ans=0;
	cin>>n>>x;
	B b[n];
	b[0].p=1;
	b[0].sum=1;
	for(int i=1;i<=n;i++){
		b[i].p=b[i-1].p*2+1;
		b[i].sum=b[i-1].sum*2+3;
	}
	for(int i=n;i>=0;i--){
		if(x>=b[i].sum){
			ans+=b[i].p;
			x-=b[i].sum;
			if(x){
				x--;
				ans++;
			}
			i++;
		}
		else x--;
	}
	cout<<ans;
	return 0;
}
