#include<bits/stdc++.h>
using namespace std;
long long k,a,b;
int main(){
	cin>>k>>a>>b;
	if(a>=k){puts("1");return 0;}
	if(b>=a){puts("-1");return 0;}
	cout<<((k-a)/(a-b)+((k-a)%(a-b)>=1?1:0))*2+1<<endl;
	return 0;
}