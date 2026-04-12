#include<bits/stdc++.h>
using namespace std;
long long a,b,c,s;
int main(){
	cin>>a>>b>>c;
	if(b<a&&b<=c)
		cout<<-1<<endl;
	else if(a<=b)
		cout<<1<<endl;
	else{
		if((a-b)%(b-c)>=1)
			s=1;
		cout<<((a-b)/(b-c)+s)*2+1<<endl; 
	}
	return 0; 
}