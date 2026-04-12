#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int dice[6],kari[6],sum,n;
string str;

int main(){
	while(1){
		sum=0;
		for(int i=0;i<6;i++){dice[i]=i+1;kari[i]=dice[i];}
		sum+=dice[0];
		cin>>n;
		if(n==0){break;}
		for(int i=0;i<n;i++){
			cin>>str;
			if(str=="North"){
				dice[4]=kari[0];
				dice[5]=kari[4];
				dice[1]=kari[5];
				dice[0]=kari[1];
			}
			else if(str=="East"){
				dice[2]=kari[0];
				dice[5]=kari[2];
				dice[3]=kari[5];
				dice[0]=kari[3];
			}
			else if(str=="West"){
				dice[3]=kari[0];
				dice[5]=kari[3];
				dice[2]=kari[5];
				dice[0]=kari[2];
			}
			else if(str=="South"){
				dice[1]=kari[0];
				dice[5]=kari[1];
				dice[4]=kari[5];
				dice[0]=kari[4];
			}
			else if(str=="Right"){
				dice[1]=kari[2];
				dice[3]=kari[1];
				dice[4]=kari[3];
				dice[2]=kari[4];
			}
			else if(str=="Left"){
				dice[2]=kari[1];
				dice[4]=kari[2];
				dice[3]=kari[4];
				dice[1]=kari[3];
			}
			for(int i=0;i<6;i++){kari[i]=dice[i];}
			sum+=dice[0];
		}
		cout<<sum<<endl;

	}
	
	return 0;
}