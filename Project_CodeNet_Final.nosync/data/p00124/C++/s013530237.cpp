#include<stdio.h> 
#include<string> 
#include<iostream> 
using namespace std;   
struct TA{ 
	string name; int po; int rr;
};     
int main(){ 
	int n; 
	struct TA N[11];  
	bool ty=true;
	while(1){ scanf("%d",&n);
	if(n==0)break; 
		if(ty==false)cout<<endl;
	ty=false;
	for(int i=0;i<n;i++) 

	
	{cin>>N[i].name;int a,b,c; cin>>a>>b>>c; 
	N[i].po=a*3+c*1; N[i].rr=i; } 
	for(int i=0;i<n;i++) for(int j=n-1;j>i;j--) 
		if(N[j].po>N[j-1].po){struct TA T=N[j];N[j]=N[j-1];N[j-1]=T;}   
		for(int i=0;i<n;i++) 
		cout<<N[i].name<<","<<N[i].po<<endl;         
	}
	return 0;
} 