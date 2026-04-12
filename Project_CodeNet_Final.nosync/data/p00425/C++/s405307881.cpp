#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int i,m,n;
	string Dice;
	int sum;
	int num[6],s[6];
	while(1){
		sum=1;
		for(i=0;i<6;i++){
			s[i]=i+1;
			num[i]=i+1;
		}
		cin>>n;
		if(n==0){
			break;
		}
		for(m=0;m<n;m++){
			cin>>Dice;
			if(Dice=="North"){
				num[0]=s[1];
				num[1]=s[5];
				num[4]=s[0];
				num[5]=s[4];
				s[0]=num[0];
				s[1]=num[1];
				s[4]=num[4];
				s[5]=num[5];
			}
			else if(Dice=="East"){
				num[0]=s[3];
				num[2]=s[0];
				num[3]=s[5];
				num[5]=s[2];
				s[0]=num[0];
				s[2]=num[2];
				s[3]=num[3];
				s[5]=num[5];
			}
			else if(Dice=="West"){
				num[0]=s[2];
				num[2]=s[5];
				num[3]=s[0];
				num[5]=s[3];
				s[0]=num[0];
				s[2]=num[2];
				s[3]=num[3];
				s[5]=num[5];
			}
			else if(Dice=="South"){
				num[0]=s[4];
				num[1]=s[0];
				num[4]=s[5];
				num[5]=s[1];
				s[0]=num[0];
				s[1]=num[1];
				s[4]=num[4];
				s[5]=num[5];
			}
			else if(Dice=="Right"){
				num[1]=s[2];
				num[2]=s[4];
				num[3]=s[1];
				num[4]=s[3];
				s[1]=num[1];
				s[2]=num[2];
				s[3]=num[3];
				s[4]=num[4];
			}
			else{
				num[1]=s[3];
				num[2]=s[1];
				num[3]=s[4];
				num[4]=s[2];
				s[1]=num[1];
				s[2]=num[2];
				s[3]=num[3];
				s[4]=num[4];
			}
			sum=sum+num[0];
		}
		cout<<sum<<endl;
	}
	return 0;
}