#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

enum{UE,MAE,MIGI,HIDARI,USIRO,SITA};

int daice[6]={1,2,3,4,5,6};
int n,wa,tmp;
char sizi[100];

int main(void){

	while(1){
		wa=1;
		for(int i=0;i<6;i++) daice[i]=i+1;

		cin>>n;
		if(n==0) break;

		for(int i=0;i<n;i++){
			cin>>sizi;
			if(!strcmp(sizi,"North")){
				tmp=daice[UE];
				daice[UE]=daice[MAE];
				daice[MAE]=daice[SITA];
				daice[SITA]=daice[USIRO];
				daice[USIRO]=tmp;
				wa+=daice[UE];
			}
			else if(!strcmp(sizi,"South")){
				tmp=daice[UE];
				daice[UE]=daice[USIRO];
				daice[USIRO]=daice[SITA];
				daice[SITA]=daice[MAE];
				daice[MAE]=tmp;
				wa+=daice[UE];
			}
			else if(!strcmp(sizi,"West")){
				tmp=daice[UE];
				daice[UE]=daice[MIGI];
				daice[MIGI]=daice[SITA];
				daice[SITA]=daice[HIDARI];
				daice[HIDARI]=tmp;
				wa+=daice[UE];
			}
			else if(!strcmp(sizi,"East")){
				tmp=daice[UE];
				daice[UE]=daice[HIDARI];
				daice[HIDARI]=daice[SITA];
				daice[SITA]=daice[MIGI];
				daice[MIGI]=tmp;
				wa+=daice[UE];
			}
			else if(!strcmp(sizi,"Right")){
				tmp=daice[MAE];
				daice[MAE]=daice[MIGI];
				daice[MIGI]=daice[USIRO];
				daice[USIRO]=daice[HIDARI];
				daice[HIDARI]=tmp;
				wa+=daice[UE];
			}
			else if(!strcmp(sizi,"Left")){
				tmp=daice[MAE];
				daice[MAE]=daice[HIDARI];
				daice[HIDARI]=daice[USIRO];
				daice[USIRO]=daice[MIGI];
				daice[MIGI]=tmp;
				wa+=daice[UE];
			}
			/*for(int i=0;i<6;i++) cout<<daice[i]<<",";
			cout<<endl;*/
		}
		cout<<wa<<endl;
	}

	return 0;
}