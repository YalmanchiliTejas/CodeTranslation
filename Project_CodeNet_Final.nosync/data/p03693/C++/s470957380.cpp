#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,b,c;
	cin>>a>>b>>c;
	n=a*100+b*10+c;
	if(n%4==0)cout<<"YES";
	else cout<<"NO";
	return 0;
}