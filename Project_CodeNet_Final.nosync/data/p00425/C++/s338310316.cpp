#include <iostream>
using namespace std;
int dice[3];
int main() {
	while(true){
	int N,sum=0,l;
	dice[0]=1;
	dice[1]=2;
	dice[2]=3;
	string aim;
	cin >> N;
	if(N==0)
		break;
	for(int i=0;i<N;i++){
		cin >> aim;
		int w,x;
		if(aim=="East"){
			w=2;
			x=0;
		}
		else if(aim=="West"){
			w=0;
			x=2;
		}
		else if(aim=="North"){
			w=0;
			x=1;
		}
		else if(aim=="South"){
			w=1;
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
	
		
	cout << sum+1 << endl;
	}
	// your code goes here
	return 0;
}