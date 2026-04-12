#include <bits/stdc++.h>
using namespace std;
int main(){
	long N,X,Z[51],i;cin>>N>>X;Z[0]=1;
	for(i=1;i<=N;i++)Z[i]=Z[i-1]*2+3;
	long ans=0,l=1,h=Z[N],m=(h+l)/2;
	while(1){
		if(m<=X){l=m,ans+=(h-l)/2+1;}
		else h=m;
		l++,h--;
		if(l>h) break;
		m=(h+l)/2;
    }
	cout<<ans;
}