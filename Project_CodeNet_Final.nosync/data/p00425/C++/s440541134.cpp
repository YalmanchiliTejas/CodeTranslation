#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 

using namespace std;

int main()
{
	int top,bot,sum,n,side[4],tmp;
	string s;

	while(1){
		cin>>n; if(n==0) return 0;
		top=1; bot=6; sum=1;
		side[0]=2;side[1]=3;side[2]=5;side[3]=4;
		for(int i=0;i<n;i++){
			cin>>s;
			if(s=="North"){
				top=side[0];side[0]=bot;side[2]=7-bot;
				bot=7-top;
			}else if(s=="East"){
				top=side[3];side[3]=bot;side[1]=7-bot;
				bot=7-top;
			}else if(s=="West"){
				top=side[1];side[1]=bot;side[3]=7-bot;
				bot=7-top;
			}else if(s=="South"){
				top=side[2];side[2]=bot;side[0]=7-bot;
				bot=7-top;
			}else if(s=="Right"){
				tmp=side[0];side[0]=side[1];side[1]=side[2];
				side[2]=side[3];side[3]=tmp;
			}else{
				tmp=side[0];side[0]=side[3];side[3]=side[2];
				side[2]=side[1];side[1]=tmp;
			}
			sum+=top;
		}
		cout<<sum<<endl;
	}
}