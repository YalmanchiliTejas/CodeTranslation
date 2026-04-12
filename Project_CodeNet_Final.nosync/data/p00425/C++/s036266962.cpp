#include<iostream>
#include<string>
using namespace std;
int main(){
	int i,x,dummy;
	string str,N="North",E="East",W="West",S="South",R="Right",L="Left";
	while(1){
		cin>>x;
		if(x==0){
		break;
		}
		int ans=1;
		int n=5,e=3,w=4,s=2,a=1,b=6;
		for(i=0;i<x;i++){
		cin>>str;
			if(str==N){
				dummy=a;
				a=s;
				s=b;
				b=n;
				n=dummy;
			}
			else if(str==E){
				dummy=a;
				a=w;
				w=b;
				b=e;
				e=dummy;
			}
			else if(str==W){
				dummy=a;
				a=e;
				e=b;
				b=w;
				w=dummy;
			}
			else if(str==S){
				dummy=a;
				a=n;
				n=b;
				b=s;
				s=dummy;
			}
			else if(str==R){
				dummy=n;
				n=w;
				w=s;
				s=e;
				e=dummy;
			}
			else{
				dummy=n;
				n=e;
				e=s;
				s=w;
				w=dummy;
			}
			ans+=a;
		}
		cout<<ans<<endl;
	}
	return 0;
}