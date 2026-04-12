#include<bits/stdc++.h>
using namespace std;
int main() {
	long long k,a,b;
		//a b c 
	cin>>k>>a>>b;
	if(a>=k) {
		cout<<1<<endl;
		return 0;
	}
	if(b>=a) {
		cout<<-1<<endl;
		return 0;
	}
	if((k-b)%(a-b)>=1)cout<<((k-a)/(a-b)+1)*2+1<<endl;
	else cout<<((k-a)/(a-b))*2+1<<endl;
	return 0;
}