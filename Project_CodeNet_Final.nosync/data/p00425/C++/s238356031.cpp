#include<iostream>
#include<string>

int main(){
	int n;
	while(std::cin>>n){
		if(n==0)break;
		int sum=1,dice[6],dice_a[6];
		for(int i=0;i<6;i++)dice[i]=i+1,dice_a[i]=i+1;
		for(int i=0;i<n;i++){
			std::string str;
			std::cin>>str;
			if(str=="North"){
				dice[0]=dice_a[1];
				dice[1]=dice_a[5];
				dice[4]=dice_a[0];
				dice[5]=dice_a[4];
			}if(str=="East"){
				dice[0]=dice_a[3];
				dice[2]=dice_a[0];
				dice[5]=dice_a[2];
				dice[3]=dice_a[5];
			}if(str=="West"){
				dice[0]=dice_a[2];
				dice[2]=dice_a[5];
				dice[5]=dice_a[3];
				dice[3]=dice_a[0];
			}if(str=="South"){
				dice[0]=dice_a[4];
				dice[1]=dice_a[0];
				dice[5]=dice_a[1];
				dice[4]=dice_a[5];
			}if(str=="Right"){
				dice[1]=dice_a[2];
				dice[2]=dice_a[4];
				dice[4]=dice_a[3];
				dice[3]=dice_a[1];
			}if(str=="Left"){
				dice[1]=dice_a[3];
				dice[2]=dice_a[1];
				dice[4]=dice_a[2];
				dice[3]=dice_a[4];
			}
			for(int i=0;i<6;i++)dice_a[i]=dice[i];
			sum+=dice[0];
		}
		std::cout<<sum<<std::endl;
	}
	return 0;
}