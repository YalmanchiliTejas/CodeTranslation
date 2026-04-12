#include <bits/stdc++.h>
using namespace std;
long long k,a,b,i;
int main(){
	cin>>k>>a>>b;
	if(k<=a){
		cout<<1<<endl;
		exit(0);
	}
	if(a<=b){
		cout<<-1<<endl;
		return 0;
	}
	if((k-a)%(a-b)>=1)i=1;
    cout<<((k-a)/(a-b)+i)*2+1<<endl;
	return 0;
} 