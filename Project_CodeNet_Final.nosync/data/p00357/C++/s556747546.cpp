#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n,d[300001];
	bool flg=false;
	
	cin>>n;
	
	int i;
	
	int MAX=1;
	for(i=0;i<n;i++){
		cin>>d[i];
	}
	for(i=0;i<n;i++){
		d[i]=d[i]/10;
		MAX--;
		if(MAX<d[i]) MAX=d[i];
		if(MAX==0){
			flg=true;
			break;
		}
	}
	
	MAX=1;
	
	if(!flg){
		for(i=n-1;i>=0;i--){
			MAX--;
			if(MAX<d[i]) MAX=d[i];
			if(MAX==0){
				flg=true;
				break;
			}
		}
	}
	
	cout<<((flg)?"no":"yes")<<endl;
	
	return 0;
}
		
			
	
		
	
	
