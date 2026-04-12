#include<iostream>
#include<string>
using namespace std;

int main(){
	int num,i;
	string m;
	
	while(1){
		int sum=1;
		int temp;
		int over=1,under=6,n=5,s=2,w=3,e=4;
		
		cin>>num;
		if(num==0) break;
		
		for(i=0;i<num;i++){
			cin>>m;
			if(m=="North"){
				temp=over;
				over=s;
				s=under;
				under=n;
				n=temp;
			}
			else if(m=="South"){
				temp=over;
				over=n;
				n=under;
				under=s;
				s=temp;
			}
			else if(m=="East"){
				temp=over;
				over=e;
				e=under;
				under=w;
				w=temp;
			}
			else if(m=="West"){
				temp=over;
				over=w;
				w=under;
				under=e;
				e=temp;
			}
			else if(m=="Left"){
				temp=s;
				s=e;
				e=n;
				n=w;
				w=temp;
			}
			else if(m=="Right"){
				temp=s;
				s=w;
				w=n;
				n=e;
				e=temp;
			}
			sum+=over;
		}
		cout<<sum<<endl;
	}
return 0;
}