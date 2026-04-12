#include<bits/stdc++.h>
using namespace std;
long long k,a,b,t;
int main(){
	cin>>k>>a>>b;
	if(b>=a and a<k)cout<<-1<<endl;
	else if(k<=a)cout<<1<<endl;
	else if((k-a)%(a-b)==0)cout<<(k-a)/(a-b)*2+1<<endl;
	else cout<<(k-a)/(a-b)*2+3<<endl;
}