#include <iostream>
using namespace std;
int main(){
	int n,i;
	int w,x,l;
	int sum=0;
	string aim;
	while(1){
		int dice[3]={1,2,3};
		cin>>n;
		if(n==0){
			break;
		}
		for(i=0;i<n;i++){
			cin>>aim;
			if(aim=="North"){
				w=0;
				x=1;
			}
			else if(aim=="South"){
				w=1;
				x=0;
			}
			else if(aim=="West"){
				w=0;
				x=2;

			}
			else if(aim=="East"){
               w=2;
               x=0;
			}
			else if(aim=="Right"){
              w=1;
              x=2;
			}
			else if(aim=="Left"){
              w=2;
              x=1;
			}
			l=7-dice[w];
			dice[w]=dice[x];
			dice[x]=l;
			sum+=dice[0];
		}
		cout<<sum+1<<endl;
		sum=0;
	}
	return 0;
}