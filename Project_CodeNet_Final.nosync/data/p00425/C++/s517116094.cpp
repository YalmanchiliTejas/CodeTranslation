#include<iostream>
#include<string>
using namespace std;
void sort(int n[4],int a[6]);
int main(){
	int n[4]={1,2,6,5};
	int s[4]={1,5,6,2};
	int e[4]={1,4,6,3};
	int w[4]={1,3,6,4};
	int r[4]={2,3,5,4};
	int l[4]={2,4,5,3};
	int in;
	int sum;
	string st;
	while(cin>>in,in!=0){
		int a[6]={1,2,3,4,5,6};
		sum=1;
		for(int i=0;i<in;i++){
			cin>>st;
			if(st[0]=='N')sort(n,a);
			else if(st[0]=='N')sort(n,a);	
			else if(st[0]=='S')sort(s,a);	
			else if(st[0]=='E')sort(e,a);	
			else if(st[0]=='W')sort(w,a);	
			else if(st[0]=='R')sort(r,a);		
			else if(st[0]=='L')sort(l,a);	
			//for(int i=0;i<6;i++)cout<<a[i]<<" ";
			//cout<<endl;
			sum+=a[0];
		}
		cout<<sum<<endl;
	}
}



void sort(int n[4],int a[6]){
	int t;
	t=a[n[0]-1];
	for(int i=0;i<3;i++)
		a[n[i]-1]=a[n[i+1]-1];
	a[n[3]-1]=t;
}