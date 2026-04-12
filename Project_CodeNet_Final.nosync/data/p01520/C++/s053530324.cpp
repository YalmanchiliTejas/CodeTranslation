#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int main(){
	int n,t,e,x,ans=-1;
	cin>>n>>t>>e;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(t%x<=e||(t/x+1)*x-t<=e){
			ans=i;break;
		}
	}
	cout<<ans<<endl;
	return 0;
}	