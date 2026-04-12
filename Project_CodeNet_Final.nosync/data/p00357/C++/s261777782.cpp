#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n,t[300001];
	int i,mx,flg,flg1;
	
	cin>>n;
	
	for(i=0;i<n;i++) cin>>t[i];
	
	flg=0,mx=-1;
	for(i=0;i<n;i++){
	
		mx=max(mx,t[i]+i*10);
			
		if(mx<(i+1)*10){
			flg=1;
			break;
		}
	}
	
	for(i=0;i<n/2;i++) swap(t[i],t[n-i-1]);
	
	flg1=0,mx=-1;
	for(i=0;i<n;i++){
	
		mx=max(mx,t[i]+i*10);
			
		if(mx<(i+1)*10){
			flg1=1;
			break;
		}
	}
	
//	cout<<flg<<" "<<flg1<<endl;
	
	if(flg==0&&flg1==0) cout<<"yes"<<endl; 
	else cout<<"no"<<endl;
	
	return 0;
}	
